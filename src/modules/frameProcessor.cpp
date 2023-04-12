#include "frameProcessor.h"

int FrameProcessor::processFrame(Mat& frame) {
    //eye status for each new frame
    bool eyeStatus = 0;

    //detect faces
    face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(100, 100));//detecting the face
    
    if (faces.size() == 0) {
        return FACE_NOT_FOUND;
    }
    //there should only be 1 face detected, so maybe change the code later on
    for (int i = 0; i < faces.size(); i++) { 
        
        Mat faceROI = frame(faces[i]);//Taking area of the face as Region of Interest for eyes//
        eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 4, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));//detect eyes in every face//
        
        for (size_t j = 0; j < eyes.size(); j++) { //for locating eyes//

            Mat eyeROI = faceROI(eyes[j]);

            //if any of the eyes is detected as open
            eyeStatus = blinkDetector.detect(eyeROI) || eyeStatus;
        }
    }
    if (false == eyeStatus) {
        return EYES_CLOSED;
    }
    return EYES_OPEN;
}


void FrameProcessor::threadLoop() {
    while (isOn) {
        //read the frame from the global var
        std::unique_lock<std::mutex> lock(frame_mutex);
        frame_cv.wait(lock, [] { return !frame_queue.empty(); });  // Wait until new data is available
        Mat frame = frame_queue.front();
        frame_queue.pop();
        processed = 1;
        lock.unlock();
        frame_cv.notify_one(); 

        int retVal = processFrame(frame);

        //send the retval to the buffer global var
        std::unique_lock<std::mutex> lock_buffer(status_mutex);
        status_cv.wait(lock_buffer, [] { return !loading; });  // Wait for sleep detection to load and empty the queue
        status_queue.push(retVal);
        lock_buffer.unlock();
        status_cv.notify_one();

        //std::cout << "Frame processed: " << retVal << std::endl;
    }
}

void FrameProcessor::start() {
    isOn = true;
    frameProcessorThread = std::thread(&FrameProcessor::threadLoop, this);
}

/*!
 * Frees thread resources and stops processing, must be called prior to program exit.
 */
void FrameProcessor::stop() {
    isOn = false;
    frameProcessorThread.join();
}
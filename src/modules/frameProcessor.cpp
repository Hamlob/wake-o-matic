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
        
        //Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);//getting the center of the face//
        //ellipse(frame, center, Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);//draw an ellipse on the face//
        
        Mat faceROI = frame(faces[i]);//Taking area of the face as Region of Interest for eyes//
        eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 4, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));//detect eyes in every face//
        
        for (size_t j = 0; j < eyes.size(); j++) { //for locating eyes//
            //Point center(faces[i].x + eyes[j].x + eyes[j].width * 0.5, faces[i].y + eyes[j].y + eyes[j].height * 0.5);//getting the centers of both eyes//
            //int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);//declaring radius of the eye enclosing circles//
            //circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);//drawing circle around both eyes//
            
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
        std::unique_lock<std::mutex> lock(queue_mutex);
        queue_cv.wait(lock, [] { return !frame_queue.empty(); });  // Wait until new data is available
        Mat frame = frame_queue.front();
        frame_queue.pop();
        processed = 1;
        lock.unlock();
        queue_cv.notify_one(); 

        int retVal = processFrame(frame);
        std::cout << "Frame processed " << retVal << std::endl;
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
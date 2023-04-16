#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include "modules/eyeStatus.h"
#include "modules/camera.h" //https://github.com/berndporr/opencv-camera-callback
#include <opencv2/opencv.hpp>
#include "modules/frameProcessor.h"
#include "modules/sleepDetect.h"
#include "modules/actionStateMachine.h"
#include <mutex>
#include <condition_variable>
#include "modules/logging.h"

using namespace std;
using namespace cv;

//queue, mutex and cv for raw frames
std::queue<Mat> frame_queue;
std::mutex frame_mutex;
std::condition_variable frame_cv;
bool processed = 1;

//queue, mutex and cv for status of the eyes 
std::queue<int> status_queue;
std::mutex status_mutex;
std::condition_variable status_cv;
bool loading = 0;			//flag that represents that the value

//mutex and cv for action stateMachine
std::mutex action_mutex;
std::condition_variable action_cv;

//variable holding the current sleep status (-1 no face, 0 asleep, 1 awake)
int sleepStatus = NOFACE;

//defines a SceneCallback structure with the required callback for the camera class
struct MyCallback : Camera::SceneCallback {

	// Locks the mutex and pushes the frame into the queue, then unlocks it and notify the other thread
	void nextScene(const cv::Mat& frame) {

		std::unique_lock<std::mutex> lock(frame_mutex);
		frame_cv.wait(lock, [] { return processed; });  // Wait until new data is available
		frame_queue.push(frame);

		//std::cout << "Pushed frame. " << std::endl;

		processed = 0; // resets the processed flag
		lock.unlock();
		frame_cv.notify_one();  // Notify the consumer thread that new data is available
	}
};



int main() {
	#ifdef USE_LOGGING
	init_logging();
	BOOST_LOG_TRIVIAL(info) << "Logging Started";
	#endif

	//create camera object for capturing frames in a separate thread
	Camera camera;

	//create callback object
	MyCallback cb;

	//create frame processor
	FrameProcessor frameProcessor;

	//sleep detection
	SleepDetect sleepDetector;

	//create action state machine
	ActionStateMachine action;

	//create a window, only for debuggin
	//cv::namedWindow("window", cv::WINDOW_AUTOSIZE);

	//registers callback function in camera object
	camera.registerSceneCallback(&cb);

	//creates a thread with blocking video capture to call the registered callback when frame is captured
	camera.start(0,200);

	std::cout << "Camera started" << std::endl;

	//creates a thread for processing frames, when new frames are ready
	frameProcessor.start();

	std::cout << "Frame processing started" << std::endl;

	std::cout << "Action state machine started" << std::endl;

	for (int i = 0; i < 10; i++) {

		//load the frame buffer into the frame processor and clear the buffer using mutex
		std::unique_lock<std::mutex> lock_buffer(status_mutex);
		status_cv.wait(lock_buffer, [] { return !status_queue.empty(); });  // Wait for sleep detection to load and empty the queue
		loading = 1;

		while (!status_queue.empty()) {
			sleepDetector.load(status_queue.front());
			status_queue.pop();
		}

		loading = 0;
		lock_buffer.unlock();
		status_cv.notify_one();


		//checking frame queue size
		std::cout << "Number of unprocessed frames in queue: " << frame_queue.size() << std::endl;

		//check the size of buffer for processing
		std::cout << "number of eye status values to be processed: " << sleepDetector.bufferSize() << std::endl;

		//process the buffer
		sleepStatus = sleepDetector.detect();

		std::cout << "Sleep status: " << sleepStatus << std::endl;

		//doing corresponding action
		action.changeState(sleepStatus);

		//sleep for 1 sec
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}


	//finishes the threads
	action.changeState(AWAKE);
	camera.stop();
	frameProcessor.stop();
	
	

	return 0;
}

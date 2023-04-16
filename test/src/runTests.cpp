#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include "../../src/modules/eyeStatus.h"
#include "../../src/modules/camera.h" //https://github.com/berndporr/opencv-camera-callback
#include <opencv2/opencv.hpp>
#include "../../src/modules/frameProcessor.h"
#include "../../src/modules/sleepDetect.h"
#include "../../src/modules/actionStateMachine.h"
#include "tests.h"
#include "cppTests.h"

//uncomment for testing on actual device, commented out for github CI since the github server does not have access to camera, so the test would always fail
//#define CAMERA_TEST_ON

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


/**
 * @brief Test runner
 * Optional run_test program to execute each test method. 
 * Alternatively, CTest can be configured to compile individual tests 
 * and run the test methods directly.
 */
int main() {
    std::cout << "Tests started!" << std::endl;

	#ifdef CAMERA_TEST_ON
	cameraTest();
	#endif
	
	eyeStatusTest();

	frameProcessorTest();

    test_sleeping_flag_set();
    test_warning_flag_set();
    test_listener_triggered_by_sleeping();
    test_listener_triggered_by_warning();

    std::cout << "Tests (4) succeeded!" << std::endl;
    return 0; // You can put a 1 here to see later that it would generate an error
}
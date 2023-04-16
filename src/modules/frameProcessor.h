#pragma once
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include "eyeStatus.h"
#include "camera.h" //https://github.com/berndporr/opencv-camera-callback
#include <opencv2/opencv.hpp>
#include <condition_variable>
#include <mutex>

using namespace std;
using namespace cv;

#define FACE_NOT_FOUND -1
#define EYES_CLOSED 0
#define EYES_OPEN 1

extern std::queue<Mat> frame_queue;
extern std::mutex frame_mutex;
extern std::condition_variable frame_cv;
extern bool processed;

extern std::queue<int> status_queue;
extern std::mutex status_mutex;
extern std::condition_variable status_cv;
extern bool loading;

/**
 * @brief The frameProcessor class handles the detection of the driver eye status.
 * It runs in a separate thread and waits for the frames from the camera.
 * When a frame is ready, it detects the positions of the eyes and calls @see eyeStatus class with the images of just the eyes.
 * Depends on the output of the eyeStatus, the frameProcessor stores the status of the eyes for each frame in global queue.
 * It also handles the case where no face is detected, or no eyes are detected but face is.
 * The values stored in queue are 1 for eyes open, 0 for eyes closed/not found, -1 for no face detected.
 */
class FrameProcessor
{
public:

	/// @brief Starts the frameProcessing in separate thread
	void start();

	/// @brief Stops the frame processing thread.
	void stop();

	/// @brief the constructor loads the cascade classifiers and prints an error if they are not loaded correctly.
	FrameProcessor(std::string faceCascadePath = "../src/data/haarcascade_frontalface_alt.xml", std::string eyeCascadePath = "../src/data/haarcascade_eye.xml"){

		//declaring a CascadeClassifier object for eyes and face and loading appropriate haarcascades//
		std::cout << "loading cascades" << std::endl;
		face_cascade.load(faceCascadePath);
		eyes_cascade.load(eyeCascadePath);
		if(!face_cascade.empty() && !eyes_cascade.empty()){
			std::cout << "loaded cascades" << std::endl;
		}else{
			std::cout << "problem loading cascades" << std::endl;
		}
	}

	/**
	 * @brief Analyzes the frame and returns corresponding value for open, closed eyes or driver not detected.
	 * 
	 * @param frame The picture of the camera containing the driver.
	 * @return int Returns 1 if the driver has eyes open, 0 if eyes closed, and -1 if the driver is not detected.
	 */
	int processFrame(Mat& frame);


private:
	void threadLoop();
	bool isOn = false;
	std::thread frameProcessorThread;

	CascadeClassifier face_cascade, eyes_cascade;
	EyeStatus blinkDetector;
	vector<Rect>eyes;//declaring a vector named eyes//
	vector<Rect>faces;//Declaring a vector named faces//
};


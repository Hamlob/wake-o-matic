#pragma once
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include "eyeStatus.h"
#include "camera.h" //https://github.com/berndporr/opencv-camera-callback
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define FACE_NOT_FOUND -1
#define EYES_CLOSED 0
#define EYES_OPEN 1

extern std::queue<Mat> frame_queue;
extern std::mutex queue_mutex;
extern std::condition_variable queue_cv;
extern bool processed;


class FrameProcessor
{
public:

	//debuggin only, displays the frame
	//void displayFrame();

	//starts the thread for processing frames
	void start();

	//stops the processing thread
	void stop();

	//create eye detection and eye status objects, and cascade classifier objects
	FrameProcessor(){


		//declaring a CascadeClassifier object for eyes and face and loading appropriate haarcascades//
		
		face_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml");
		eyes_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_eye.xml");
		

	}

private:
	//processes the input frame and returns a value
	int processFrame(Mat& frame);
	
	void threadLoop();
	bool isOn = false;
	std::thread frameProcessorThread;

	CascadeClassifier face_cascade, eyes_cascade;
	EyeStatus blinkDetector;
	vector<Rect>eyes;//declaring a vector named eyes//
	vector<Rect>faces;//Declaring a vector named faces//
};


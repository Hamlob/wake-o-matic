#include "tests.h"


void cameraTest() {
	cv::Mat img;
	cv::VideoCapture cap;
	cap.open(0);
	assertm(cap.isOpened(), "Camera opening failed");
	cap.read(img);
	assertm(!img.empty(), "Image is empty");
	return;
}

void eyeStatusTest() {
	cv::Mat closed = cv::imread("eyeClosed.jpg");
	cv::Mat open = cv::imread("eyeOpen.jpg");

	EyeStatus blinkDetector;

	bool statusClosed = blinkDetector.detect(closed);
	bool statusOpen = blinkDetector.detect(open);

	assertm(!statusClosed, "Closed eye image falsely detected as open eye");
	assertm(statusOpen, "Open eye image falsely detected as closed eye");
	return;
}


void frameProcessorTest() {

	cv::Mat noface = cv::imread("noface.jpg");
	cv::Mat face_closedeyes = cv::imread("face_closedeyes.jpg");
	cv::Mat face_openeyes = cv::imread("face_openeyes.jpg");

	FrameProcessor frameProcessor;

	int statusNoFace = frameProcessor.processFrame(noface);
	int statusClosedEyes = frameProcessor.processFrame(face_closedeyes);
	int statusOpenEyes = frameProcessor.processFrame(face_openeyes);

	assertm(FACE_NOT_FOUND == statusNoFace, "Incorrect detection for picture noface.jpg");
	assertm(EYES_CLOSED == statusClosedEyes, "Incorrect detection for picture face_closedeyes.jpg");
	assertm(EYES_OPEN == statusOpenEyes, "Incorrect detection for picture face_openeyes.jpg");

	return;
}
//
//void Tests::sleepDetectTest();
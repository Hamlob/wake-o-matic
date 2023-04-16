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
	cv::Mat closed = cv::imread("../../../test/images/eyeClosed.jpg");
	cv::Mat open = cv::imread("../../../test/images/eyeOpen.jpg");
	
	assertm(!closed.empty(), "Image of a closed eye is empty");
	assertm(!open.empty(), "Image of an open eye is empty");

	EyeStatus blinkDetector;

	bool statusClosed = blinkDetector.detect(closed);
	bool statusOpen = blinkDetector.detect(open);

	assertm(!statusClosed, "Closed eye image falsely detected as open eye");
	assertm(statusOpen, "Open eye image falsely detected as closed eye");
	return;
}


void frameProcessorTest() {

	cv::Mat noface = cv::imread("../../../test/images/noface.jpg");
	cv::Mat face_closedeyes = cv::imread("../../../test/images/face_closedeyes.jpg");
	cv::Mat face_openeyes = cv::imread("../../../test/images/face_openeyes.jpg");

	FrameProcessor frameProcessor("../../../src/data/haarcascade_frontalface_alt.xml","../../../src/data/haarcascade_eye.xml");

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

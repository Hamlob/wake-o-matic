#include "../../src/modules/camera.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace std;

Camera camera;
cv::Mat frame;

int caught = 0;



//defines a SceneCallback structure with the required callback, this will be done inside other classes
//why does the camera class uses struct for lambda function?
struct MyCallback : Camera::SceneCallback {
	
	void nextScene(const cv::Mat& mat) {

		caught += 1;
		frame = mat;
		return;
	}
};



int main() {
	
	cv::namedWindow("window", cv::WINDOW_AUTOSIZE);

	//create the callback
	MyCallback cb;

	//register callback and start frame capture
	camera.registerSceneCallback(&cb);
	camera.start();
	//wait for some frames to be captured
	sleep(1);
	camera.stop();

	std::cout << "" << caught << " frames caught in 1 sec." << std::endl;

	//save the frame and check whether a valid frame was saved into the specified directory
	cv::imwrite("test.jpg",frame);
	
	cv::Mat frame = cv::imread("test.jpg", 0);
	if (frame.empty()){	
    std::cout << "!!! Failed imread(): image not found" << std::endl;
	}
	else{
		std::cout << "Image captured and saved successfuly into test.jpg" << std::endl;
	}

	//display the frame
	cv::imshow("window", frame);
	cv::waitKey(0);



	return 0;
}

#include "camera.h" //https://github.com/berndporr/opencv-camera-callback
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;



bool catched = 0;



//defines a SceneCallback structure with the required callback, this will be done inside other classes
//why does the camera class uses struct for lambda function?
struct MyCallback : Camera::SceneCallback {
	virtual void nextScene(const cv::Mat& mat) {

		if (catched==1) {
			cv::imshow("window", mat);
			cv::waitKey(0);
			return;
		}
		catched = 1;
		cout << "Frame catched";
		cv::imwrite("some.jpg", mat);
		cout << "image saved";
		cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
		cv::imshow("window", mat);
		cv::waitKey(0);
		
		
		return;
	}
};



int main() {
	
	//create callback object
	MyCallback cb;
	Camera camera;
	//creates camera object
	


	//creates face detection object(to be implemented); 
	//input: camera objects sends the frame through mycallback here,
	//**this class calls filter class to do the filtering of the coordinates of ROI
	//output:	1)if face/eyes is detected:	 callback to sleepdetect, with ROI containing eyes(possibly face), whose position was filtered to remove noise
	//			2)if face is not detected:	callback straight to logging;			
	// ------------
	//EyeDetect eyeDetect;

	//create a filter object (to be implemented)
	// input: coordinates of ROIs from eye detection
	// output(no callback): filtered coordinates to reduce noise and misdetections (moving average/LPF?) 
	// --------------
	//Filter filter;

	//create sleep detection object(to be implemented);
	// input: filtered frames of eyes/face
	// output: callback to logging with boolean values: true for closed eyes, false for open eyes;
	// ----------------------
	//SleepDetect sleepDetect;

	//create logging object (to be implemented)
	// input: boolean values
	// output: callback to state machine with history of loggin? not sure
	//Log log;

	//create actionStateMachine object (to be implemented);
	// input: logging history
	// output: callback to action (alarm, warning, ...nothing if open eyes detected
	//ActionStateMachine asm;


	//registers callback function in camera object
	camera.registerSceneCallback(&cb);

	//creates a thread with blocking video capture to call the registered callback when frame is captured
	camera.start();

	
	
	
	//finishes the thread and stops recording 
	//**(what circumstances will need this? not detected face for long time?)
	return 0;
}
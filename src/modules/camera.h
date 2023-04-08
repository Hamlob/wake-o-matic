#pragma once
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

/*!
 * Camera class with callback
 * GNU GPL v3.0
 * (C) 2022
 * [Ross Gardiner](https://github.com/rossGardiner)
 * [Adam Frew](https://github.com/Saweenbarra)
 * [Alban Joseph](https://github.com/albanjoseph)
 * [Lewis Russell](https://github.com/charger4241)
 * Bernd Porr
 */
class Camera {
public:
	/**
	 * Callback which needs to be implemented by the client
	 **/
	struct SceneCallback {
		virtual void nextScene(const cv::Mat& mat) = 0;
	};

	/**
	 * Default constructor
	 **/
	Camera() = default;

	/**
	 * Starts the acquisition from the camera
	 * and then the callback is called at the framerate.
	 **/
	void start(int deviceID = 0, int apiID = 0);

	/**
	 * Stops the data aqusisition
	 **/
	void stop();

	/**
	 * Registers the callback which receives the
	 * frames.
	 **/
	void registerSceneCallback(SceneCallback* sc) {
		sceneCallback = sc;
	}

private:
	void postFrame();
	void threadLoop();
	cv::VideoCapture videoCapture;
	std::thread cameraThread;
	bool isOn = false;
	SceneCallback* sceneCallback = nullptr;
};
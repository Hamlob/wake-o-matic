#pragma once
#include <opencv2/opencv.hpp>
#include <cassert>
#include "eyeStatus.h"
#include "frameProcessor.h"

#define assertm(exp, msg) assert(((void)msg, exp))

void cameraTest();

void eyeStatusTest();

void frameProcessorTest();

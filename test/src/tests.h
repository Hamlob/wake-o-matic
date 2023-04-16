#pragma once
#include <opencv2/opencv.hpp>
#include <cassert>
#include "../../src/modules/eyeStatus.h"
#include "../../src/modules/frameProcessor.h"

#define assertm(exp, msg) assert(((void)msg, exp))

void cameraTest();

void eyeStatusTest();

void frameProcessorTest();

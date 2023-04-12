#pragma once
#include <thread>
#include "sleepDetect.h"
#include <iostream>
#include <mutex>
#include <condition_variable>


//mutex and cv for action stateMachine
extern std::mutex action_mutex;
extern std::condition_variable action_cv;

class ActionStateMachine
{
public:

	void start();

	void stop();

	void changeState(int state);

	void doAction(int sleepStatus);

	ActionStateMachine() = default;

private:
	void outputAlarm();
	void outputWarning();
	void threadLoop();
	bool isOn = false;
	int currentState = AWAKE;
	std::thread actionThread;
};


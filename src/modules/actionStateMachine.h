#pragma once
#include <thread>
#include "sleepDetect.h"
#include <iostream>
#include <mutex>
#include <condition_variable>


//mutex and cv for action stateMachine
extern std::mutex action_mutex;
extern std::condition_variable action_cv;

/** @brief class that handles the appropriate action depending on the sleep status:
 * plays warning when the driver is not detected, or alarm when the driver is asleep.
 * 
 * ### USAGE:
 * Change state using @see changeState() and the class handles the appropriate actions accordingly.
 */
class ActionStateMachine
{
public:

	/** @brief Changes the current state of the state machine and does the appropriate action accordingly.
	 *  @param state A new state to be changed to.
	 */
	void changeState(int state);

	int getState(){
		return currentState;
	}

	ActionStateMachine() = default;

private:
	void start();
	void stop();
	void doAction(int sleepStatus);
	void outputAlarm();
	void outputWarning();
	void threadLoop();
	bool isOn = false;
	int currentState = AWAKE;
	std::thread actionThread;
};


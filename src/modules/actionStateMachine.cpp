#include "actionStateMachine.h"

void ActionStateMachine::doAction(int sleepStatus) {
	if (SLEEPING == sleepStatus) {
		std::cout << "Play alarm " << std::endl;
		outputAlarm();
	}

	else if (NOFACE == sleepStatus) {
		std::cout << "Play Warning" << std::endl;
		outputWarning();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	return;
}
 
//changes current state and takes appropriate action
void ActionStateMachine::changeState(int state) {

	//Returns if there is no change is state.
	if (state != currentState) {
		
		//update current state
		currentState = state;

		//Starts the thread if no thread is createdand current state requires action(SLEEPING or NOFACE).
		if (!isOn && AWAKE != currentState) {
			start();
			return;
		}

		//stops thread if thread is active and driver is AWAKE
		if (isOn && AWAKE == currentState) {
			stop();
		}
	}
	return;
}


void ActionStateMachine::threadLoop() {
	while (isOn) {
		doAction(currentState);
	}
}

//starts a separate thread for the action state machine
void ActionStateMachine::start() {
	isOn = true;
	actionThread = std::thread(&ActionStateMachine::threadLoop, this);
}

//signals the cv wait to stop waiting and joins the thread
void ActionStateMachine::stop() {
	isOn = false;
	actionThread.join();
}

void ActionStateMachine::outputAlarm(){
    std::system("amixer set PCM unmute");
    // std::system("amixer set PCM 100%");
    if(0 != std::system("aplay ../wav/alarm.wav")){
        throw std::runtime_error("error");
    };
}

void ActionStateMachine::outputWarning(){
    std::system("amixer set PCM unmute");
    // std::system("amixer set PCM 100%");
    if(0 != std::system("aplay ../wav/warning.wav")){
        throw std::runtime_error("error");
    };
}
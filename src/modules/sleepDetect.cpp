#include "sleepDetect.h"


int SleepDetect::bufferSize() {
	return buffer.size();
}

void SleepDetect::load(int val) {
	buffer.push_back(val);
}

int SleepDetect::detect() {

	int openCounter = 0;
	int closedCounter = 0;
	int nofaceCounter = 0;

	for (int i = 0; i < buffer.size(); i++) {
		if (buffer[i] == 1) {
			openCounter += 1;
		}
		else if (buffer[i] == 0) {
			closedCounter += 1;
		}
		else{
			nofaceCounter += 1;
		}
	}

	//clear the buffer
	buffer.clear();

	if (openCounter > closedCounter && openCounter > nofaceCounter) {
		return AWAKE;
	}

	if (closedCounter > openCounter && closedCounter > nofaceCounter){
		return SLEEPING;
	}

	return NOFACE;
	
}

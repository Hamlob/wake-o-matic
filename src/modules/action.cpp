#include "action.h"

void Action::threadLoop() {
    while(deviceActive){
        if(flagChanged == true){
            ActionResult actionResult = completeAction();           // TODO: make this log a message when logging functionality is complete.
            std::this_thread::sleep_for(sleepTimeBetweenActions_ms);
            flagChanged = false;
        }
    }
}

Action::ActionResult Action::completeAction(){
    if(sleepingFlag){
        try{
            outputAlarm();
        } catch(...){
            return error;
        }
        return alarm;
    } else if (warningFlag){
        try{
            outputWarning();
        } catch(...){
            return error;
        }
        return warning;
    }
    return none;
}

void Action::activate(){
    deviceActive = true;
    actionThread = std::thread(&Action::threadLoop, this);
}

void Action::deactivate(){
    deviceActive = false;
    actionThread.join();
}

void Action::setSleepingFlag(bool newVal){
    sleepingFlag = newVal;
    flagChanged = true;
}

void Action::setWarningFlag(bool newVal){
    warningFlag = newVal;
    flagChanged = true;
}

void Action::setSleepTimeBetweenActions_ms(long newTime_ms){
    sleepTimeBetweenActions_ms = std::chrono::milliseconds(newTime_ms);
}

void Action::outputAlarm(){
    std::system("amixer set PCM unmute");
    // std::system("amixer set PCM 100%");
    if(0 != std::system("aplay ../wav/alarm.wav")){
        throw std::runtime_error("error");
    };
}

void Action::outputWarning(){
    std::system("amixer set PCM unmute");
    // std::system("amixer set PCM 100%");
    if(0 != std::system("aplay ../wav/warning.wav")){
        throw std::runtime_error("error");
    };
}
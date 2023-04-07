#pragma once

#include <stdlib.h>
#include <thread>
#include <iostream>

class Action {
    public:
        struct ActionCallback {
            virtual void nextAction(bool warning, bool sleeping) = 0;
        };

        Action() = default;

        void registerActionCallback(ActionCallback* ac){
            actionCallback = ac;
        }

        void activate();
        void deactivate();

        void setSleepingFlag(bool newVal);
        void setWarningFlag(bool newVal);

    private:
        void outputAlarm();
        void outputWarning();
        void threadLoop();

        std::thread actionThread;

        bool warningFlag = false;
        bool sleepingFlag = false;
        
        bool flagChanged = false;

        bool deviceActive = false;
        ActionCallback* actionCallback = nullptr;
};
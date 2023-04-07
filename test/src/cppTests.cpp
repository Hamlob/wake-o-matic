#include "cppTests.h"
#include<unistd.h> 

bool test_listener_triggered_by_sleeping(){
    struct MyCallback : Action::ActionCallback {
        bool callbackCalled = false;
        virtual void nextAction(bool warning, bool sleeping){
            callbackCalled = true;
        }
    };
    MyCallback myCallback;
    Action myAction;
    myAction.registerActionCallback(&myCallback);
    myAction.activate();

    myAction.setSleepingFlag(true);
    sleep(0.2);
    myAction.deactivate();
    return myCallback.callbackCalled;
}

bool test_listener_triggered_by_warning(){
    struct MyCallback : Action::ActionCallback {
        bool callbackCalled = false;
        virtual void nextAction(bool warning, bool sleeping){
            callbackCalled = true;
        }
    };
    MyCallback myCallback;
    Action myAction;
    myAction.registerActionCallback(&myCallback);
    myAction.activate();

    myAction.setWarningFlag(true);
    sleep(0.2);
    myAction.deactivate();
    return myCallback.callbackCalled;
}
#include "cppTests.h"


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

    myAction.setSleepingFlag(true);

    return myCallback.callbackCalled;
}

// bool test_listener_triggered_by_warning(){
//     struct MyCallback : Action::ActionCallback {
//         bool callbackCalled = false;
//         virtual void nextAction(bool warning, bool sleeping){
//             callbackCalled = true;
//         }
//     };
//     MyCallback myCallback;
//     Action myAction;
//     myAction.registerActionCallback(&myCallback);

//     myAction.setWarningFlag(true);

//     return myCallback.callbackCalled;
// }
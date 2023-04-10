#include "cppTests.h"
#include<unistd.h> 
#include <cassert>

bool test_sleeping_flag_set(){
    Action myAction;
    myAction.activate();

    myAction.setSleepingFlag(true);
    bool result = myAction.getSleepingFlag();

    myAction.deactivate();
    assertm(result, "sleeping flag not set");
    return true;
}

bool test_warning_flag_set(){
    Action myAction;
    myAction.activate();
    
    myAction.setWarningFlag(true);
    bool result = myAction.getWarningFlag();

    myAction.deactivate();
    assertm(result, "warning flag not set");
    return true;
}

bool test_listener_triggered_by_sleeping(){
    Action myAction;
    myAction.setSleepTimeBetweenActions_ms(1000);
    myAction.activate();

    myAction.setSleepingFlag(true);
    const auto start = std::chrono::high_resolution_clock::now();
    sleep(0.2);
    myAction.deactivate();
    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double, std::milli> elapsed = end - start;

    assertm((elapsed > std::chrono::milliseconds(1000)), "threadLoop exited impossibly quickly");
    return true;
}

bool test_listener_triggered_by_warning(){
    Action myAction;
    myAction.setSleepTimeBetweenActions_ms(1000);
    myAction.activate();

    myAction.setWarningFlag(true);
    const auto start = std::chrono::high_resolution_clock::now();
    sleep(0.2);
    myAction.deactivate();
    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double, std::milli> elapsed = end - start;

    assertm((elapsed > std::chrono::milliseconds(1000)), "threadLoop exited impossibly quickly");
    return true;
}
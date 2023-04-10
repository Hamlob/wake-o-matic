#pragma once
#include <stdlib.h>
#include "../../src/modules/action.h"

#define assertm(exp, msg) assert(((void)msg, exp))

bool test_sleeping_flag_set();
bool test_warning_flag_set();
bool test_listener_triggered_by_sleeping();
bool test_listener_triggered_by_warning();
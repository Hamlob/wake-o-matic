#pragma once
#include <stdlib.h>
#include "../../src/modules/action.h"

#define assertm(exp, msg) assert(((void)msg, exp))

/// @brief Creates action thread and ensures sleeping flag is set correctly
/// @return True if test completed
bool test_sleeping_flag_set();

/// @brief Creates action thread and ensures warning flag is set correctly
/// @return True if test completed
bool test_warning_flag_set();

/// @brief Creates action thread and checks thread executes action logic when a flag is set
/// @return True if test completed
bool test_listener_triggered_by_sleeping();

/// @brief Creates action thread and checks thread executes action logic when a flag is set
/// @return True if test completed
bool test_listener_triggered_by_warning();
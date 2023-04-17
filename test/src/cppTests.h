#pragma once
#include <stdlib.h>
#include "../../src/modules/actionStateMachine.h"

#define assertm(exp, msg) assert(((void)msg, exp))

/// @brief Creates action object and checks that it activates by state change to !AWAKE
/// @return True if test completed
bool test_action_activated_by_state_sleeping();

/// @brief Creates action object and checks that it deactivates by state change to AWAKE
/// @return True if test completed
bool test_action_deactivated_by_state_awake();
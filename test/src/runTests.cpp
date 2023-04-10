#include <iostream>
#include <cassert>
#include "cppTests.h"

/**
 * @brief Test runner
 * Optional run_test program to execute each test method. 
 * Alternatively, CTest can be configured to compile individual tests 
 * and run the test methods directly.
 */
int main() {
    std::cout << "Tests started!" << std::endl;

    test_sleeping_flag_set();
    test_warning_flag_set();
    test_listener_triggered_by_sleeping();
    test_listener_triggered_by_warning();

    std::cout << "Tests (4) succeeded!" << std::endl;
    return 0; // You can put a 1 here to see later that it would generate an error
}
#include <iostream>

int main() {
    std::cout << "Tests started!" << std::endl;

    test_listener_triggered_by_sleeping();
    test_listener_triggered_by_warning();
    // test_speaker_plays_warning();
    // test_speaker_plays_alarm();
    // test_no_action_if_no_flags();

    std::cout << "Tests (0) succeeded!" << std::endl;
    return 0; // You can put a 1 here to see later that it would generate an error
}
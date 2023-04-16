cmake_minimum_required(VERSION 3.16)

set(TEST_SOURCE_FILES tests.h tests.cpp)
set(TEST_EXECUTABLE runTests.cpp)

add_library(wake-o-matic-tests ${TEST_SOURCE_FILES})

target_include_directories(wake-o-matic-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(wake-o-matic-tester_CAPTURE_DETECT ${TEST_EXECUTABLE})
target_link_libraries(wake-o-matic-tester_CAPTURE_DETECT LINK_PUBLIC wake-o-matic-tests)

target_link_libraries(wake-o-matic-tester_CAPTURE_DETECT LINK_PUBLIC wake-o-matic-modules)



add_test(NAME unitTest_CAPTURE_DETECT COMMAND wake-o-matic-tester_CAPTURE_DETECT)

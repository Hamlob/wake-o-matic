cmake_minimum_required(VERSION 3.16)

set(TEST_SOURCE_FILES runTests.cpp cppTests.h cppTests.cpp)
set(TEST_EXECUTABLE )

add_library(wake-o-matic-tests ${TEST_SOURCE_FILES})

target_include_directories(wake-o-matic-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(wake-o-matic-tester ${TEST_SOURCE_FILES})
target_link_libraries(wake-o-matic-tester LINK_PUBLIC wake-o-matic-tests)

# target_link_libraries(wake-o-matic-tester LINK_PUBLIC wake-o-matic-main)
target_link_libraries(wake-o-matic-tester LINK_PUBLIC wake-o-matic-modules)



add_test(NAME unitTesting COMMAND wake-o-matic-tester)
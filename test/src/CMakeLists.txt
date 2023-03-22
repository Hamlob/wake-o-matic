cmake_minimum_required(VERSION 3.2)

set(TEST_SOURCE_FILES )
set(TEST_EXECUTABLE )

add_library(wake-o-matic-tests TEST_SOURCE_FILES)

target_include_directories(wake-o-matic-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(wake-o-matic-tester tester.cpp)
target_link_library(wake-o-matic-tester LINK_PUBLIC wake-o-matic-tests)

target_link_library(wake-o-matic-tester LINK_PUBLIC wake-o-matic-main)
target_link_library(wake-o-matic-tester LINK_PUBLIC wake-o-matic-modules)
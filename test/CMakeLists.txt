cmake_minimum_required(VERSION 3.16)
include(ExternalProject)

project(Wake-o-matic-tests)

include(CTest)
enable_testing()

add_subdirectory(src)

# target_link_libraries(wake-o-matic-tester LINK_PUBLIC cppunit)
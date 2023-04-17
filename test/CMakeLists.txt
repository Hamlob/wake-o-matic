cmake_minimum_required(VERSION 3.16)
include(ExternalProject)

project(Wake-o-matic-tests)

include(CTest)
enable_testing()

add_subdirectory(src)


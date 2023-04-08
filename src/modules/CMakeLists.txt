cmake_minimum_required(VERSION 3.16)

set(MODULE_SOURCE_FILES camera.cpp eyeStatus.cpp frameProcessor.cpp filter.cpp)


add_library (wake-o-matic-modules ${MODULE_SOURCE_FILES})


target_include_directories (wake-o-matic-modules PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

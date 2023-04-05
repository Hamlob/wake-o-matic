
set(MODULE_SOURCE_FILES tempFile.cpp)


add_library (wake-o-matic-modules ${MODULE_SOURCE_FILES})


target_include_directories (wake-o-matic-modules PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.16)

set(MAIN_SOURCE_FILES main.cpp)
set(CUSTOM_LINK_LIBRARIES ${OpenMP_LIBS} ${OpenCV_LIBS})

if(SAVE_LOG)
    set(CUSTOM_LINK_LIBRARIES ${CUSTOM_LINK_LIBRARIES} ${Boost_LIBS} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
endif()

add_subdirectory(modules)

# Make sure the compiler can find include files for our library
# when other libraries or executables link to wake-o-matic

add_executable(wake-o-matic-main ${MAIN_SOURCE_FILES})
set_target_properties(wake-o-matic-main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_include_directories (wake-o-matic-main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(wake-o-matic-main LINK_PUBLIC wake-o-matic-modules ${CUSTOM_LINK_LIBRARIES})
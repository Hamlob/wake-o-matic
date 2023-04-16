# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required(VERSION 3.16)
project (
    "Wake-o-matic"
    VERSION 0.1.0
    LANGUAGES CXX
)

#Define the used cmake standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -pthread")

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

#include OpenCV library
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS})

#include OpenMP
find_package(OpenMP)

#include BOOST library
if(SAVE_LOG)
    ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
    find_package(Boost REQUIRED COMPONENTS thread log log_setup program_options)
    include_directories(${Boost_INCLUDE_DIRS})

    set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -DUSE_LOGGING -DBOOST_LOG_DYN_LINK -lboost_log -lboost_thread -lboost_system -lboost_log_setup")
endif()

#include(cmake/StandardSettings.cmake)
#include(cmake/StaticAnalyzers.cmake)
#include(cmake/Utils.cmake)

include(CTest)
enable_testing()

# Add the subdirectories relevant to code
add_subdirectory (src)
add_subdirectory (test)

# install(TARGETS wake-o-matic-main)

# enable_testing()
add_test(NAME main COMMAND wake-o-matic-main)

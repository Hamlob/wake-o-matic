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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -pthread -DBOOST_LOG_DYN_LINK")

#include OpenCV library
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS})

#include OpenMP
find_package(OpenMP)

#include BOOST library
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package(Boost 1.67 REQUIRED COMPONENTS thread log log_setup program_options)
include_directories(${Boost_INCLUDE_DIRS})

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

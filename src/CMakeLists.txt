cmake_minimum_required(VERSION 3.16)


add_subdirectory(modules)

# Make sure the compiler can find include files for our library
# when other libraries or executables link to wake-o-matic

add_executable(wake-o-matic-main main.cpp)
target_include_directories (wake-o-matic-main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(wake-o-matic-main LINK_PUBLIC wake-o-matic-modules)
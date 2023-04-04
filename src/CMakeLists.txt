cmake_minimum_required(VERSION 3.2)


# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_subdirectory(modules)

# Make sure the compiler can find include files for our library
# when other libraries or executables link to wake-o-matic
target_include_directories (wake-o-matic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executables(wake-o-matic-main main.cpp)
target_link_libraries(wake-o-matic-main LINK_PUBLIC wake-o-matic-modules)
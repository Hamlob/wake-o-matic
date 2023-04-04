
set(MODULE_SOURCE_FILES )

# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (wake-o-matic-modules ${MODULE_SOURCE_FILES})

# Make sure the compiler can find include files for our modules library
# when other libraries or executables link to Hello
target_include_directories (wake-o-matic-modules PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
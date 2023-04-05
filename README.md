# Wake-o-matic
Microsleep and drowsiness detection for drivers using Raspberry Pi 4. Uses openCV library for eye recognition.

Feel free to visit [our GitHub wiki](github.com/Hamlob/wake-o-matic/wiki) to learn more about the project!


## File Structure
`docs` contains documentation and diagrams produced through the project
`include` and `lib` are blank folders, populated by CMake when built locally
`src` contains main source code to build
| `src/modules` contains C++ files for various procedures
`test`
| `test/lib` is a blank folder, populated by CMake for test-specific libraries
| `test/src` contains C++ unit testing files (CppUnit)
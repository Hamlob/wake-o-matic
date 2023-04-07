# Wake-o-matic
Microsleep and drowsiness detection for drivers using Raspberry Pi 4. Uses openCV library for eye recognition.

Feel free to visit [our GitHub wiki](https://github.com/Hamlob/wake-o-matic/wiki) to learn more about the project!

## Requirements
This project is designed to be deployed under the following requirements, and has only been tested as such; however you may find ways to make it work on other systems.
* [Raspberry Pi](https://www.raspberrypi.com/products/raspberry-pi-3-model-b-plus/) (model 3B+ or newer) and compatible power supply
* [Night vision camera module](https://shop.pimoroni.com/products/night-vision-camera-module-for-raspberry-pi), we recommend the 70° lens, but both work
* [Raspberry Pi OS](https://www.raspberrypi.com/software/operating-systems/) (aka Raspian) 5.10 or newer
* An audio amplifier/speaker compatible with rpi, [like this one](https://shop.pimoroni.com/products/adafruit-stemma-speaker-plug-and-play-audio-amplifier), along with the necessary cables to connect everything

## Getting Started
### Installation
1. Clone the repository in a convenient location
2. `cd bin`
3. `cmake ..`
4. `cmake --build .`

### Run Wake-o-matic
From the `/bin/` folder, enter `./wake-o-matic-main`

### Running the tests (not required)
We utilise CTest, built-in with CMake, to issue our unit tests. You can run the tests yourself by entering `ctest` from the `/bin/` directory.


## File Structure
`docs` contains documentation and diagrams produced through the project
`include` and `lib` are blank folders, populated by CMake when built locally
`src` contains main source code to build
| `src/modules` contains C++ files for various sub-procedures
`test`
| `test/lib` is a blank folder, populated by CMake for test-specific libraries
| `test/src` contains C++ unit testing files (CppUnit)
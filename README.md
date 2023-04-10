# Wake-o-matic
Microsleep and drowsiness detection for drivers using Raspberry Pi 4. Uses openCV library for eye recognition.

## Follow Us!
[Check out our Linktree](https://linktr.ee/wakeomatic) for all of our social medias!

[Visit our documentation](https://hamlob.github.io/wake-o-matic/) to learn how to use the project.

## About the Project
Driving while drowsy is a danger that all of us are aware of, however most of us can probably think of an example of a time we took the risk in order to get to our destination. [According to road safety charity, Brake](https://www.brake.org.uk/get-involved/take-action/mybrake/knowledge-centre/driver-fatigue#:~:text=Worldwide%2C%20it%20is%20estimated%20that,road%20crashes%20are%20fatigue%2Drelated.), 1 in 8 drivers admit to falling asleep at the wheel, with an estimated 10-20% of UK traffic accidents being fatigue related.

Of course, this project won't fix all the problems, but we aim to provide a tool to help drivers understand their limits _before_ an accident occurs. Besides, who better to try to find a solution than a bunch of sleepy, final-year engineering students!

## Why are we doing this?
Wake-o-Matic is project born out of a coursework assignment at the School of Engineering, University of Glasgow. 

The open-ended assignment brief is to develop a real-time solution to a problem, which lead us to address a problem that has affected the entire team at some point.

## Getting Started
### Requirements
This project is designed to be deployed under the following requirements, and has only been tested as such; however you may find ways to make it work on other systems.
* [Raspberry Pi](https://www.raspberrypi.com/products/raspberry-pi-3-model-b-plus/) (model 3B+ or newer) and compatible power supply
* [Night vision camera module](https://shop.pimoroni.com/products/night-vision-camera-module-for-raspberry-pi), we recommend the 70° lens, but both work
* [Raspberry Pi OS](https://www.raspberrypi.com/software/operating-systems/) (aka Raspian) 5.10 or newer
* An audio amplifier/speaker compatible with rpi, [like this one](https://shop.pimoroni.com/products/adafruit-stemma-speaker-plug-and-play-audio-amplifier), along with the necessary cables to connect everything

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

## Founders
* [Charlie Cameron](https://github.com/Jenibluere)
* [Gabriel Dzharadat](https://github.com/GJaradat)
* [Peter Konecny](https://github.com/Hamlob)
* [Ying Wang](https://github.com/MrMeerkat)

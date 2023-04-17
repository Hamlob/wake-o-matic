<p align="center" style="margin-bottom: 0px !important;">
    <img width="200" src="https://raw.githubusercontent.com/Hamlob/wake-o-matic/e1107be7e28d248bb5c01b58180b3d375b0f93ae/docs/img/logo_vector.svg" alt="Wake-o-matic logo" align="center">
</p>
<h1 align="center" style="margin-top: 0px;">Wake-o-matic</h1>
<p align="center" >Microsleep and drowsiness detection for drivers using Raspberry Pi. Uses openCV library for eye recognition.</p>

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
    - With OpenCV installed (Recommended: V4.0.0) [We followed this guide](https://robu.in/installing-opencv-using-cmake-in-raspberry-pi/) but you can also save time by [Cross-compiling OpenCV using a separate device](https://solarianprogrammer.com/2018/12/18/cross-compile-opencv-raspberry-pi-raspbian/).
    - Boost installed (Optional, recommended: V1.71): `sudo apt-get install libboost-all-dev`
    - CMake installed (V3.16 or newer)
* [Night vision camera module](https://shop.pimoroni.com/products/night-vision-camera-module-for-raspberry-pi), we recommend the 70° lens, but both work well.
* [Raspberry Pi OS](https://www.raspberrypi.com/software/operating-systems/) (aka Raspian) (Recommended: V5.10 or newer)
* An audio amplifier/speaker compatible with rpi, [like this one](https://shop.pimoroni.com/products/adafruit-stemma-speaker-plug-and-play-audio-amplifier), along with the necessary cables to connect everything

### Installation
1. Clone the repository in a convenient location
2. `cd bin`
3. `cmake ..` Note: if you would like to include the debug log when you run the code, add the `-DSAVE_LOG` flag.
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

## Roadmap
Here's a general roadmap of the milestones that we are working towards. You can find out more in our [release log](https://github.com/Hamlob/wake-o-matic/releases).

=>**V1.0**: We've been working hard to get our MVP fully working, which we can now say we have! Our product is still a bit rough around the edges, but the basic features work and we have it all open-source for you!

**V1.1**: In this version, we aim to have found most of the edge-case bugs and fixed them all. We will also have some of our optional extra features included. We may also have a new revision of the 3D-printed enclosure in this version, should we see any need for an upgrade. By now, we hope to have a good foundation of documentation, troubleshooting resources and tutorials, to make it easy to have your own wake-o-matic!

**V1.2**: Mobile app! We hope to have a companion app for our users to customise their device settings all day and night (except when driving :o)!

**V1.3**: This version will introduce our corporate features, allowing the wake-o-matic to be deployed in rental/company cars and configured to send certain telemetry to a server (subject to legal matters).

**V1.4**: Production model preparation: by now, we should have our wheels firmly on the road, and will have sorted out the logistical matters of a production release. Stay tuned, because the wake-o-matic could become available to buy off-the-shelf!
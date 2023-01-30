# Humanoid Robot Wrestling Controller Example

[![webots.cloud - Competition](https://img.shields.io/badge/webots.cloud-Competition-007ACC)][1]

## Alice C++ controller

Minimalist C++ controller example for the [Humanoid Robot Wrestling Competition](https://github.com/cyberbotics/wrestling).
Demonstrates how to play a simple motion file. We use the [Motion class](https://cyberbotics.com/doc/reference/motion?tab-language=c++) from Webots.

Here is the [participant.cpp](./controllers/participant/participant.cpp) file:

``` C++
#include <webots/Robot.hpp>
#include <webots/utils/Motion.hpp>

using namespace webots;

int main() {
  // Robot initialization
  Robot *robot = new Robot();

  // Motion files are text files containing pre-recorded positions of the robot's joints
  Motion *motion = new Motion("../motions/HandWave.motion");
  // We play the hand-waving motion on loop
  motion->setLoop(true);
  motion->play();

  const int time_step = robot->getBasicTimeStep();
  // Mandatory function to make the simulation run
  while (robot->step(time_step) != -1);

  // Robot cleanup
  delete robot;
  return 0;
}
```

To compile the C++ code, the [Dockerfile](./controllers/Dockerfile) must be updated; the environment variables needed for python can be removed and a call to `make` is needed to compile the source code:

``` Dockerfile
FROM cyberbotics/webots.cloud:R2023a-ubuntu20.04

# Environment variables needed for Webots
# https://cyberbotics.com/doc/guide/running-extern-robot-controllers#remote-extern-controllers
ENV LD_LIBRARY_PATH=${WEBOTS_HOME}/lib/controller:${LD_LIBRARY_PATH}
ARG WEBOTS_CONTROLLER_URL
ENV WEBOTS_CONTROLLER_URL=${WEBOTS_CONTROLLER_URL}

# Copies all the files of the controllers folder into the docker container
RUN mkdir -p /usr/local/webots-project/controllers
COPY . /usr/local/webots-project/controllers

WORKDIR /usr/local/webots-project/controllers/participant

# Compile controller
RUN make
    
ENTRYPOINT ["./participant"]
```

[Bob](https://github.com/cyberbotics/wrestling-bob) is a more advanced robot controller able to win against Alice.

[1]: https://webots.cloud/run?version=R2022b&url=https%3A%2F%2Fgithub.com%2Fcyberbotics%2Fwrestling%2Fblob%2Fmain%2Fworlds%2Fwrestling.wbt&type=competition "Leaderboard"

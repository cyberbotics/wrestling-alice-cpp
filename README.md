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

[Bob](https://github.com/cyberbotics/wrestling-bob) is a more advanced robot controller able to win against Alice.

[1]: https://webots.cloud/run?version=R2022b&url=https%3A%2F%2Fgithub.com%2Fcyberbotics%2Fwrestling%2Fblob%2Fmain%2Fworlds%2Fwrestling.wbt&type=competition "Leaderboard"

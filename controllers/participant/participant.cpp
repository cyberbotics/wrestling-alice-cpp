/*
 * Copyright 1996-2023 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
   Description: Minimalist C++ controller example for the Robot Wrestling Tournament.
   Demonstrates how to play a simple motion file.
*/

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

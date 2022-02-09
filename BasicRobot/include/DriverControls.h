//Header Guard
#pragma once
#include "BrainUI.h"

namespace control
{
  // void ButtonExample();
  // void AxisExample();
  // void StepUp();
  //void StepDown();
  // void TestSong();

  /**
  * General control loop for the driver
  */
  extern void ControlBot();
  extern void TestSong();
  extern void MotorControl();
  extern void buttonPresses();

  extern int maxRPM;

  extern int MRvel;
  extern int MLvel;
}

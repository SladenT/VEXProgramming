/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\SURoC                                            */
/*    Created:      Thu Jan 13 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor15              motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "DriverControls.h"
#include "ControllerUI.h"

using namespace vex;

bool exec;

//Main Loop
int main() {

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


  exec = true;
  while (exec)
  {
    control::ControlBot();
    UI::DisplayControls();
  }
  

}

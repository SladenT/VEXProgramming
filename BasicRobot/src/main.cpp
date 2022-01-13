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
// Controller1          controller                    
// M10                  motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "DriverControls.h"

using namespace vex;

bool exec;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  exec = true;
  while (exec)
  {
    ControlBot();    
  }
  
}

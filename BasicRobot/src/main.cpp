/*----------------------------------------------------------------------------*/
/*
    Module:       main.cpp                                                
    Authors:      Davis Tiegeler, Zachary Spiggle                                       
    Created:      18 Jan 2022                                               
    Description:  Main loop of the robot's program                             
*/
/*----------------------------------------------------------------------------*/


/* ---- START VEXCODE CONFIGURED DEVICES ----
Robot Configuration:
[Name]               [Type]        [Port(s)]
ML                   motor         14              
ML2                  motor         16  
MR                   motor         15
MR2                  motor         17  
ARM1                 motor         09
accel                inertial      10

AAM                  motor         11

---- END VEXCODE CONFIGURED DEVICES ----*/

//Includes
#include "vex.h"
#include "DriverControls.h"
#include "Kinetics.h"
#include "ai.h"

using namespace vex;

//Execute
bool exec;

//Main Loop
int main() {

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


  exec = true;

  //Infinite loop until program is force stopped
  while (exec)
  {
    
    //If in AImode, run the AI script, otherwise control manually
    if (AImode)
    {
      AI::AILoop();
    }
    else 
    {
      control::ControlBot();
    }


    Kinetics::TestPosition();

  }
}

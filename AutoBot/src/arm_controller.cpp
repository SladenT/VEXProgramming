/*----------------------------------------------------------------------------*/
/*
    Module:       arm_controller.cpp                                                
    Authors:      Davis Tiegeler, Zachary Spiggle                               
    Created:      3 Feb 2022                                               
    Description:  Defines arm controllers for main loop                     
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "robot-config.h"


using namespace vex;


namespace arm{

  int armSpeed = 0;

  //Call this in primary loop to move arm
  void moveArm(){

    ARM1.spin(directionType::rev, armSpeed, velocityUnits::rpm);

  }

}

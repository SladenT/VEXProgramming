#include "vex.h"
#include "DriverControls.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor ML = motor(PORT14, ratio18_1, false);
motor MR = motor(PORT15, ratio18_1, false);
controller Controller1 = controller(controllerType::primary);

// VEXcode generated functions



void vexcodeInit( void ) {
  
  Controller1.Screen.clearScreen();
}
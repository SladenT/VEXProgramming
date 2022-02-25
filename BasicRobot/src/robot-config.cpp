/*----------------------------------------------------------------------------*/
/*
    Module:       robot-config.cpp                                                
    Authors:      Davis Tiegeler, Zachary Spiggle, VEX                                 
    Created:      18 Jan 2022                                               
    Description:  Sets up robotics motors and devices                      
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "DriverControls.h"
#include "ControllerUI.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor ML = motor(PORT14, ratio18_1, false);
motor MR = motor(PORT15, ratio18_1, false);
motor ML2 = motor(PORT16, ratio18_1, false);
motor MR2 = motor(PORT17, ratio18_1, false);

// Claw
motor ARM1 = motor(PORT9, ratio18_1, false);

// Arm Motor
motor AAM = motor(PORT11, ratio36_1, false);

controller Controller1 = controller(controllerType::primary);
digital_out doutA = digital_out(Brain.ThreeWirePort.A);

inertial accel = inertial(PORT10);

//Custom
bool AImode = false;

void vexcodeInit( void ) {
  UI::UIRow test[3] = {UI::init, UI::init2, UI::init3};
  
  UI::ArrangeUI(test);
}
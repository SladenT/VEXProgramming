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
controller Controller1 = controller(controllerType::primary);

void vexcodeInit( void ) {
  Controller1.Screen.clearScreen();
  UI::ArrangeRow(0, UI::init);
  UI::ArrangeRow(1, UI::init2);
  UI::ArrangeRow(2, UI::init3);
}
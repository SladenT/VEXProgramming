#include "vex.h"
#include "DriverControls.h"
#include "ControllerUI.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor ML = motor(PORT14, ratio6_1, false);
motor MR = motor(PORT15, ratio6_1, false);
motor ML2 = motor(PORT16, ratio6_1, false);
motor MR2 = motor(PORT17, ratio6_1, false);

motor ARM1 = motor(PORT10, ratio6_1, false);

controller Controller1 = controller(controllerType::primary);
digital_out doutA = digital_out(Brain.ThreeWirePort.A);

inertial accel = inertial(PORT10);

bool AImode = false;

void vexcodeInit( void ) {
  UI::UIRow test[3] = {UI::init, UI::init2, UI::init3};
  
  UI::ArrangeUI(test);
}
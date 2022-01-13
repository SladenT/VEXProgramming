#include "vex.h"
#include "robot-config.h"

using namespace vex;



void ControlBot()
{
    if (Controller1.ButtonL1.pressing())
    {
      M10.spinFor(directionType::fwd, 0.1, timeUnits::sec, 100, velocityUnits::rpm);
    }
}


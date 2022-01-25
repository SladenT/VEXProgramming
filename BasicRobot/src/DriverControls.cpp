#include "vex.h"
#include "robot-config.h"

//using namespace vex;


namespace control
{
  double MRvel = 0;
  double MLvel = 0;
  double MRstickvel = 0;
  void ButtonExample()
  {
    if (Controller1.ButtonL1.pressing())
      {
        MRvel += 100;
      }
  }

  void StepUp()
  {
    MRstickvel += 1;
  }

  void StepDown()
  {
    MRstickvel -= 1;
  }

  void AxisExample()
  {
    int pos = Controller1.Axis3.position();
    MRvel += pos;
  }

  void MotorControl()
  {
    if (MRvel != 0)
    {
      MR.spin(directionType::fwd, MRvel, velocityUnits::rpm);
    }
    else
    {
      MR.stop();
    }
    if (MLvel != 0)
    {
      ML.spin(directionType::rev, MLvel, velocityUnits::rpm);
    }
    else
    {
      ML.stop();
    }
    Brain.Screen.printAt(20, 20, "Right Motor Speed: %f", MRvel);
    Brain.Screen.printAt(20, 40, "Left Motor Speed: %f", MLvel);
  }

  void MRControl()
  {
      int y = Controller1.Axis3.position();
      int x = -Controller1.Axis4.position();
      MRvel += x+y;
  }

  void MLControl()
  {
      int y = Controller1.Axis3.position();
      int x = Controller1.Axis4.position();
      MLvel += x+y;
  }
  void ControlBot()
  {
    // vel = stickvel;
    // AxisExample();
    // ButtonExample();
    // MotorControl();
    MRvel = 0;
    MLvel = 0;
    MRControl();
    MLControl();
    MotorControl();
  }
}






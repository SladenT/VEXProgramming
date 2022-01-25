#include "vex.h"
#include "robot-config.h"

using namespace vex;


namespace control
{

  //MR == Moter Right
  //ML == Motor Left

  double MRvel = 0;
  double MLvel = 0;

  //double MRstickvel = 0;

  /*
   Example on how to use a button: 
  
    Controller1.ButtonL1.pressing()
      returns boolean, can be used in if statements


    Example of axis

    int pos = Controller1.Axis3.position();
    MRvel += pos;

  */

  void MotorControl()
  {

    //Motor Right
    if (MRvel != 0)
    {
      MR.spin(directionType::fwd, MRvel, velocityUnits::rpm);
    }
    else
    {
      MR.stop();
    }

    //Motor Left
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

    Controller1.Screen.print("HI DAVIS");
  }

  void MRControl()
  {
      //Axis 3 = y direction
      int y = Controller1.Axis3.position(); //Vertical
      int x = -Controller1.Axis4.position(); //Horizontal
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
    //Set vars
    MRvel = 0;
    MLvel = 0;

    MRControl();
    MLControl();
    MotorControl();
  }
}






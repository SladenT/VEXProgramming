#include "vex.h"
#include "robot-config.h"

#include "BrainUI.h"

using namespace vex;

namespace control
{

  //MR == Moter Right
  //ML == Motor Left

  double MRvel = 0;
  double MLvel = 0;

  //double MRstickvel = 0;

  bool pressedA = 0;
  bool pressedB = 0;
  bool pressedY = 0;
  bool pressedX = 0;
  bool pressedBumper = 0; 
  

  //bumper thebumper = bumper('A');
  bumper theBumper = bumper(Brain.ThreeWirePort.A);

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


    //Brain.Screen.printAt(20, 20, "Right Motor Speed: %f", MRvel);
    //Brain.Screen.printAt(20, 40, "Left Motor Speed: %f", MLvel);
  }

  void MRControl()
  {
      //Axis 3 = y direction
      int y = Controller1.Axis3.position()*1.6; //Vertical
      int x = -Controller1.Axis4.position()*1.6; //Horizontal
      MRvel += x+y;
  }

  void MLControl()
  {
      int y = Controller1.Axis3.position()*1.6;
      int x = Controller1.Axis4.position()*1.6;
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




    //Making keylisteners here later



    //Testing log function

    //A Button Single Press
    if (Controller1.ButtonA.pressing())
    {
      if (pressedA == 0)
      {
        BrainUI::LogToScreen("Testing Log Functionality");   
        pressedA = 1; 
      }

    } else {
      pressedA = 0;
    }
  

  //B Button Single press
    if (Controller1.ButtonB.pressing())
    {
      if (pressedB == 0)
      {
        BrainUI::LogToScreen("AHHHHHHHHHHHHHHHHHHhh");   
        pressedB = 1; 
      }

    } else {
      pressedB = 0;
    }

  //Y Button
    if (Controller1.ButtonY.pressing())
    {
      if (pressedY == 0)
      {
        BrainUI::LogToScreen("Boop beep");   
        pressedY = 1; 
      }

    } else {
      pressedY = 0;
    }

  //X Button
    if (Controller1.ButtonX.pressing())
    {
      if (pressedX == 0)
      {
        BrainUI::LogToScreen("Beep boop");   
        pressedX = 1; 
      }

    } else {
      pressedX = 0;
    }


    if (theBumper.pressing())
    {
      if (pressedBumper == 0)
      {
        BrainUI::LogToScreen("OUCH");   
        pressedBumper = 1; 
      }

    } else {
      pressedBumper = 0;
    }

  }
}






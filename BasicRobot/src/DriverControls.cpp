#include "vex.h"
#include "robot-config.h"

#include "BrainUI.h"
#include "OtherUtil.h"

//For arm controls
#include "arm_controller.h"


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
  
  int maxRPM = 550;

  //int control_state = 0;

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
      MR2.spin(directionType::fwd, MRvel, velocityUnits::rpm);
    }
    else
    {
      MR.stop();
      MR2.stop();
    }

    //Motor Left
    if (MLvel != 0)
    {
      ML.spin(directionType::rev, MLvel, velocityUnits::rpm);
      ML2.spin(directionType::rev, MLvel, velocityUnits::rpm);
    }
    else
    {
      ML.stop();
      ML2.stop();
    }


    //Brain.Screen.printAt(20, 20, "Right Motor Speed: %f", MRvel);
    //Brain.Screen.printAt(20, 40, "Left Motor Speed: %f", MLvel);
  }

  void MRControl()
  {
      //Axis 3 = y direction
      int y = -Util::Lerp(0, maxRPM, Controller1.Axis3.position()/100.0); // Vertical
      int x;
      if (Controller1.Axis4.position() < 10  &&  Controller1.Axis4.position() > -10)
      {
        x = 0;
      }
      else
      {
        x = Util::Lerp(0, maxRPM, Controller1.Axis4.position()/100.0); //Horizontal
      } 
      MRvel += x+y;
  }

  void MLControl()
  {
      int y = -Util::Lerp(0, maxRPM, Controller1.Axis3.position()/100.0);
      int x;
      if (Controller1.Axis4.position() < 10 && Controller1.Axis4.position() > -10)
      {
        x = 0;
      }
      else
      {
        x = -Util::Lerp(0, maxRPM, Controller1.Axis4.position()/100.0);
      }
      MLvel += x+y;
  }


//Switch functionality
void buttonPresses(){
    //A Button Single Press
    if (Controller1.ButtonA.pressing())
    {
      if (pressedA == 0)
      {
           
        //maxRPM = 250;

        if (AImode == 0){
          AImode = 1;
          BrainUI::LogToScreen("AI Run");
          //spin();
          
        } else {
          AImode = 0;
          BrainUI::LogToScreen("STOPPING AI");
        }


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
        BrainUI::LogToScreen("Set RPM to 350");   
        maxRPM = 350;  
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
        BrainUI::LogToScreen("Set RPM to 450");   
        maxRPM = 450;

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
        BrainUI::LogToScreen("Set RPM to 550");   
        maxRPM = 550;
        pressedX = 1; 
      }

    } else {
      pressedX = 0;
    }

  }

  //AI Brain would theoretically go here
  //void AILoop(){

    //Switch to AI class?
  //}


  void ControlBot()
  {
    //Set vars
    MRvel = 0;
    MLvel = 0;


    MRControl();
    MLControl();


    MotorControl();

    buttonPresses();

    //Testing tostring
    //BrainUI::LogToScreen(Util::toString(maxRPM));

    

    


    // if (theBumper.pressing())
    // {
    //   if (pressedBumper == 0)
    //   {
    //     BrainUI::LogToScreen("OUCH");   
    //     pressedBumper = 1; 
    //   }

    // } else {
    //   pressedBumper = 0;
    // }

  }
}






/*----------------------------------------------------------------------------*/
/*
    Module:       DriverControls.cpp                                                
    Authors:      Davis Tiegeler, Zachary Spiggle                                       
    Created:      18 Jan 2022                                               
    Description:  Manual control of Robot instructions                            
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "robot-config.h"

#include "BrainUI.h"
#include "OtherUtil.h"

//For arm controls
#include "arm_controller.h"


using namespace vex;

namespace control
{

  //Initialize Variables

  //MR = Moter Right
  //ML = Motor Left
  double MRvel = 0;
  double MLvel = 0;

  // Arm Control Variable
  double AAMlvl = 0;

  //Max Speed Constants
  const int MAX_RPM = 150;
  const int MAX_ARMRPM = 150;
  

  //Controls the driving motors
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

    if (AAMlvl != 0  && ((AAM2.rotation(rotationUnits::rev) < 1.0) || (AAMlvl< 0))){
      AAM.spin(directionType::rev, AAMlvl, velocityUnits::rpm);
      AAM2.spin(directionType::fwd, AAMlvl, velocityUnits::rpm);
    } else {
      AAM.stop();
      AAM2.stop();
    }
  }

  //Controller input for Right Motors
  void MRControl()
  {
      //Axis 3 = y direction
      int y = -Util::Lerp(0, MAX_RPM, Controller1.Axis3.position()/100.0); // Vertical
      int x;

      if (Controller1.Axis4.position() < 10  &&  Controller1.Axis4.position() > -10)
      {
        x = 0;
      }
      else
      {
        x = Util::Lerp(0, MAX_RPM, Controller1.Axis4.position()/100.0); //Horizontal
      } 

      MRvel += x+y;
  }

  //Controller input for Left Motors
  void MLControl()
  {
      int y = -Util::Lerp(0, MAX_RPM, Controller1.Axis3.position()/100.0);
      int x;
      if (Controller1.Axis4.position() < 10 && Controller1.Axis4.position() > -10)
      {
        x = 0;
      }
      else
      {
        x = -Util::Lerp(0, MAX_RPM, Controller1.Axis4.position()/100.0);
      }

      MLvel += x+y;
  }

  // Input controls for the Arm
  void AAMControl()
  {
      if (Controller1.ButtonR1.pressing())
      {
        AAMlvl = MAX_ARMRPM;
      }
      else if (Controller1.ButtonR2.pressing())
      {
        AAMlvl = -MAX_ARMRPM;
      }
      else
      {
        AAMlvl = 0;
      }
  }

  //Button press checks
  void buttonPresses(){

    arm::armSpeed = 0;
    // Claw control
    if (Controller1.ButtonL2.pressing())
    {
      arm::armSpeed = 200;
    }
    if (Controller1.ButtonL1.pressing())
    {
      arm::armSpeed = -200;
    }
  }

  void ControlBot()
  {
    //reset vars
    MRvel = 0;
    MLvel = 0;

    //Get Controller motor control
    MRControl();
    MLControl();

    //Arm control
    AAMControl();

    //Move wheels
    MotorControl();

    //get button inputs and execute
    buttonPresses();

    //Move arm based on button presses
    arm::moveArm();

  }
}






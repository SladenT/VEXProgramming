/*----------------------------------------------------------------------------*/
/*
    Module:       ai.cpp                                                
    Author:       Zachary Spiggle                               
    Created:      7 Feb 2022                                               
    Description:  Defines functionality for AI to control robot and make decisions                    
*/
/*----------------------------------------------------------------------------*/

//Include statements
#include "DriverControls.h"
#include "arm_controller.h"
#include "vex.h"



namespace AI{

  // Counter variable that determines what phase our AI is in
  int section = 0;
  // Timer for phase execution
  double tTime = 0;
  // Update variable for timing
  double lastTime = 0;

  //Various robot control function
  void aispin(int speed){
    MR.spin(directionType::fwd, -speed, velocityUnits::rpm);
    ML.spin(directionType::rev, speed, velocityUnits::rpm);
  }

  void goForward(int speed){
    MR.spin(directionType::fwd, -speed, velocityUnits::rpm);
    ML.spin(directionType::rev, -speed, velocityUnits::rpm);
  }

  void reverse(int speed){
    MR.spin(directionType::fwd, speed, velocityUnits::rpm);
    ML.spin(directionType::rev, speed, velocityUnits::rpm);
  }

  void openClaw(int speed){
    ARM1.spin(directionType::fwd, speed, velocityUnits::rpm);
  }

  void closeClaw(int speed){
    ARM1.spin(directionType::rev, speed, velocityUnits::rpm);
  }

  void raiseArm(int speed)
  {
    AAM.spin(directionType::rev, speed, velocityUnits::rpm);
    AAM2.spin(directionType::fwd, speed, velocityUnits::rpm);
  }
  
  void lowerArm(int speed)
  {
    AAM.spin(directionType::fwd, speed, velocityUnits::rpm);
    AAM2.spin(directionType::rev, speed, velocityUnits::rpm);
  }

  // Overall stop function, stops every motor
  void aistop()
  {
    MR.stop();
    ML.stop();
    ARM1.stop();
    AAM.stop();
    AAM2.stop();
  }
  void stopMove()
  {
    MR.stop();
    ML.stop();
  }
  void stopArm()
  {
    AAM.stop();
    AAM2.stop();
  }
  void stopClaw()
  {
    ARM1.stop();
  }

  // Updates our lastTime variable so that we can do timing functions
  void doTime()
  {
    lastTime = vex::timer::system();
  }

  
  //MAIN AI LOOP
  void AILoop()
  {
    // Initialization of the Loop.  The IfElse format allows for non blocking code
    // To be executed, so we can do multiple things at once, if need be.
    if (section == 0)
    {
      doTime();
      tTime = 200;
      section++;
    }

    //OPEN CLAW
    if ((vex::timer::system() - lastTime < tTime) && section == 1)
    {
      openClaw(100);
      goForward(150);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 1)
    {
      doTime();
      tTime = 2000;
      stopClaw();
      section++;
    }

    //GO FOWARD
    if ((vex::timer::system() - lastTime < tTime) && section == 2)
    {
      goForward(150);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 2)
    {
      doTime();
      tTime = 500;
      section++;
      aistop();

    }

    //CLOSE CLAW
    if ((vex::timer::system() - lastTime < tTime) && section == 3)
    {
      closeClaw(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 3)
    {
      doTime();
      tTime = 2000;
      section++;
    }

    // REVERSE WITH GOAL
    if ((vex::timer::system() - lastTime < tTime) && section == 4)
    {
      reverse(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 4)
    {
      doTime();
      tTime = 0;
      section++;
      stopMove();
    }

    //RELEASE GOAL
    if ((vex::timer::system() - lastTime < tTime) && section == 5)
    {
      openClaw(50);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 5)
    {
      doTime();
      tTime = 500;
      section++;
      aistop();
    }

    if ((vex::timer::system() - lastTime < tTime) && section == 6)
    {
      reverse(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 6)
    {
      doTime();
      tTime = 170;
      section++;
      aistop();
    }

    //TURN
    if ((vex::timer::system() - lastTime < tTime) && section == 7)
    {
      aispin(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 7)
    {
      doTime();
      tTime = 2700;
      section++;
      aistop();
    }

    //FORWARD
    if ((vex::timer::system() - lastTime < tTime) && section == 8)
    {
      goForward(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 8)
    {
      doTime();
      tTime = 200;
      section++;
      aistop();
    }

    //CLOSE CLAW
    if ((vex::timer::system() - lastTime < tTime) && section == 9)
    {
      closeClaw(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 9)
    {
      doTime();
      tTime = 2700;
      section++;
    }

    //MOVE BACKWARDS FOR 2.7 SECONDS
    if ((vex::timer::system() - lastTime < tTime) && section == 10)
    {
      reverse(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 10)
    {
      doTime();
      tTime = 1000;
      section++;
      aistop();
    }

  }


}
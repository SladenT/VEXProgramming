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

  int section = 0;
  double tTime = 0;
  double lastTime = 0;

  //Control functions NEED BETTER DEFINITIONS AND MORE
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
    ARM1.spin(directionType::rev, speed, velocityUnits::rpm);
  }

  void closeClaw(int speed){
    ARM1.spin(directionType::fwd, speed, velocityUnits::rpm);
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

  void aistop()
  {
    MR.stop();
    ML.stop();
    ARM1.stop();
    AAM.stop();
    AAM2.stop();
  }



  //Empty Pseudocode, may be scrapped
  int checkFrontCarry(){


    return 0;
  }

  int checkBackCarry(){

    
    return 0;
  }

  void doTime()
  {
    lastTime = vex::timer::system();
  }

  
  //MAIN AI LOOP
  void AILoop()
  {


    if (section == 0)
    {
      doTime();
      tTime = 500;
      section++;
    }

    //OPEN CLAW
    if ((vex::timer::system() - lastTime < tTime) && section == 1)
    {
      openClaw(50);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 1)
    {
      doTime();
      tTime = 1000;
      section++;
      aistop();
    }

    //GO FOWARD
    if ((vex::timer::system() - lastTime < tTime) && section == 1)
    {
      goForward(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 1)
    {
      doTime();
      tTime = 500;
      section++;
      aistop();

    }

    //CLOSE CLAW
    if ((vex::timer::system() - lastTime < tTime) && section == 1)
    {
      closeClaw(50);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 1)
    {
      doTime();
      tTime = 1000;
      section++;
      aistop();
    }

    // REVERSE WITH GOAL
    if ((vex::timer::system() - lastTime < tTime) && section == 2)
    {
      reverse(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 2)
    {
      doTime();
      tTime = 0;
      section++;
      aistop();
    }


    if ((vex::timer::system() - lastTime < tTime) && section == 3)
    {
      aispin(100);
    }
    else if ((vex::timer::system() - lastTime > tTime) && section == 3)
    {
      doTime();
      tTime = 0;
      section++;
      aistop();
    }
  }


}
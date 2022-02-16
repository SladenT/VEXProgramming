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



namespace AI{

  //Control functions NEED BETTER DEFINITIONS AND MORE
  void spin(){
    control::MRvel = control::maxRPM;
    control::MLvel = -control::maxRPM;
  }

  void goForward(){
    control::MRvel = control::maxRPM;
    control::MLvel = control::maxRPM;
  }

  void reverse(){
    control::MRvel = -control::maxRPM;
    control::MLvel = -control::maxRPM;
  }



  //Empty Pseudocode, may be scrapped
  int checkFrontCarry(){


    return 0;
  }

  int checkBackCarry(){

    
    return 0;
  }

  
  //MAIN AI LOOP
  void AILoop(){

    //Uses control namespace to control robot
    control::MRvel = 0;
    control::MLvel = 0; 

    control::MotorControl();
    control::buttonPresses();


  }


}
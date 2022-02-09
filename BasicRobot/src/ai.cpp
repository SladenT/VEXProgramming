
#include "DriverControls.h"
#include "arm_controller.h"



namespace AI{

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




  int checkFrontCarry(){


    return 0;
  }

  int checkBackCarry(){

    
    return 0;
  }

  
  void AILoop(){

    control::MRvel = 0;
    control::MLvel = 0;

    BrainUI::LogToScreen("ai mode");  

    control::MotorControl();
    control::buttonPresses();


  }


}
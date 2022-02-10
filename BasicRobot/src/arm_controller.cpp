#include "vex.h"
#include "robot-config.h"


using namespace vex;


namespace arm{

  int armSpeed = 0;

  void Move(){
    ARM1.spin(directionType::fwd, armSpeed, velocityUnits::rpm);
  }

  void moveArm(){

    ARM1.spin(directionType::rev, armSpeed, velocityUnits::rpm);

  }

  // Adjusts angle of arm at elbow
  void adjustAngle(){

  }

  // clamps the arm
  void grab(){

  }

  // Releases 
  void release(){
    
  }

}

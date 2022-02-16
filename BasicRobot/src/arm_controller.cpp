#include "vex.h"
#include "robot-config.h"


using namespace vex;


namespace arm{

  int armSpeed = 0;


  void moveArm(){

    ARM1.spin(directionType::rev, armSpeed, velocityUnits::rpm);

  }

}

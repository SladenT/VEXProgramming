#include "vex.h"
#include "robot-config.h"
#include "BrainUI.h"

namespace Kinetics {

  int lastTime = 0;
  int currentxVel = 0;
  int currentyVel = 0;

  double testPos;
  int testTimerStop = 50000;
  int testTimer;
  bool testbool = true;

  void DoTime()
  {
    lastTime = vex::timer::system()/1000;
  }

  void DoVelocity()
  {
    int t = (vex::timer::system()/1000) - lastTime;
    currentxVel = t*accel.acceleration(axisType::xaxis);
    currentyVel = t*accel.acceleration(axisType::yaxis);
  }

  double GetPositionChange ()
  {
    int t = (vex::timer::system()/1000) - lastTime;
    double x = currentxVel*t + ((t*t*accel.acceleration(axisType::xaxis))/2);
    double y = currentyVel*t + ((t*t*accel.acceleration(axisType::yaxis))/2);
    return sqrt(pow(x,2) + pow(y, 2));
  }

  void incrementTestTimer()
  {
    testTimer += vex::timer::system() - lastTime * 1000;
  }

  void TestPosition()
  {
    if (testTimer < testTimerStop)
    {
      if (lastTime != 0)
      {
        testPos += GetPositionChange();
        incrementTestTimer();
      }
      DoTime();
      DoVelocity();
    }
    else if (testbool)
    {
      BrainUI::LogToScreen("wah");
      testbool = false;
    }
  }

}
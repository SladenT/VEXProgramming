#include "vex.h"
#include "robot-config.h"
#include "BrainUI.h"
#include "OtherUtil.h"

namespace Kinetics {

  double lastTime = 0;
  double currentxVel = 0;
  double currentyVel = 0;

  double testPos;
  int testTimerStop = 5000000;
  double testTimer;
  bool testbool = true;

  void DoTime()
  {
    lastTime = vex::timer::systemHighResolution();
  }

  void DoVelocity()
  {
    double t = (vex::timer::systemHighResolution() - lastTime);
    currentxVel = t*accel.acceleration(axisType::xaxis)*0.000000981;
    currentyVel = t*accel.acceleration(axisType::yaxis)*0.000000981;
  }

  double GetPositionChange ()
  {
    double t = ((double)vex::timer::systemHighResolution() - lastTime);
    double x = currentxVel*t + (((t*t*accel.acceleration(axisType::xaxis)*0.000000981)/2));
    double y = currentyVel*t + (((t*t*accel.acceleration(axisType::yaxis)*0.000000981)/2));
    double result =  sqrt(pow(x,2) + pow(y, 2));
    if (result > 0.1)
    {
      return result;
    }
    return 0;
  }

  void TestPosition()
  {
    if (lastTime < testTimerStop)
    {
      if (lastTime != 0)
      {
        testPos += GetPositionChange();
        BrainUI::LogToScreen(Util::toString(GetPositionChange()));
      }
      DoVelocity();
      DoTime();
    }
    else if (testbool)
    {
      BrainUI::LogToScreen(Util::toString(testPos-.4));
      testbool = false;
    }
  }

}
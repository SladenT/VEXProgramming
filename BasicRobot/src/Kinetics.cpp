/*----------------------------------------------------------------------------*/
/*
    Module:       Kinetics.cpp                                                
    Author:       Davis Tiegeler                               
    Created:      7 Feb 2022                                               
    Description:                      
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "robot-config.h"
#include "BrainUI.h"
#include "OtherUtil.h"

namespace Kinetics {

  double lastTime = 0;
  double lastxVel = 0;
  double lastyVel = 0;
  double currentxPos = 0;
  double currentyPos = 0;
  double lastxPos = 0;
  double lastyPos = 0;
  double lastxAccel = 0;
  double lastyAccel = 0;

  int mod = 1;

  double GetSmoothXAccel()
  {
    double x = accel.acceleration(axisType::xaxis);
    if (x < 0.01 && x > -0.01)
    {
      x = 0;
    }
    return x * 9.81;
  }
  double GetSmoothYAccel()
  {
    double x = accel.acceleration(axisType::yaxis);
    if (x < 0.01 && x > -0.01)
    {
      x = 0;
    }
    return x * 9.81;
  }

  void DoTime()
  {
    lastTime = vex::timer::systemHighResolution();
  }

  void DoVelocity()
  {
    double t = (vex::timer::systemHighResolution() - lastTime)/1000000;
    lastxVel = (currentxPos - lastxPos)/t;
    lastyVel = (currentyPos - lastyPos)/t;
    lastxPos = currentxPos;
    lastyPos = currentyPos;
  }

  void DoAccel()
  {
    lastxAccel = GetSmoothXAccel();
    lastyAccel = GetSmoothYAccel();
  }

  void DoPosition ()
  {
    double t = ((double)vex::timer::systemHighResolution() - lastTime)/1000000;
    double ax = (lastxAccel + GetSmoothXAccel())/2;
    double ay = (lastyAccel + GetSmoothYAccel())/2;
    currentxPos = lastxPos + lastxVel*t + (((t*t*ax)/2));
    currentyPos = lastyPos + lastyVel*t + (((t*t*ay)/2));
  }

  void TestPosition()
  {
    DoPosition();
    DoVelocity();
    DoAccel();
    DoTime();
    if (vex::timer::systemHighResolution()/mod > 1000000)
    {
      BrainUI::LogToScreen("X: " + Util::toString(currentxPos));
      BrainUI::LogToScreen("Y: " + Util::toString(currentyPos));
      mod += 1;
    }
  }

}
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
  double averagexAccel = 0;
  double averageyAccel = 0;

  int accelCounter = 0;

  double GetSmoothXAccel()
  {
    double x = accel.acceleration(axisType::xaxis);
    if (x < 0.03 && x > -0.03)
    {
      x = 0;
    }
    return x * 9.81;
  }
  double GetSmoothYAccel()
  {
    double x = accel.acceleration(axisType::yaxis);
    
    if (x < 0.03 && x > -0.03)
    {
      x = 0;
    }
    return x * 9.81;
  }

  void DoTime()
  {
    lastTime = vex::timer::system();
  }

  void DoVelocity()
  {
    double t = (vex::timer::system() - lastTime)/1000;
    // lastxVel = (currentxPos - lastxPos)/t;
    // lastyVel = (currentyPos - lastyPos)/t;
    lastxVel = lastxVel + averagexAccel * t;
    lastyVel = lastyVel + averageyAccel * t;
    lastxPos = currentxPos;
    lastyPos = currentyPos;
    averagexAccel = 0;
    averageyAccel = 0;
    accelCounter = 0;
  }

  void DoPosition ()
  {
    double t = ((double)vex::timer::system() - lastTime)/1000;
    currentxPos = lastxPos + lastxVel*t + (t*t*averagexAccel);
    currentyPos = lastyPos + lastyVel*t + (t*t*averageyAccel);
  }

  void AverageAccelCount()
  {
    // Need to change the values so that they change according to rotation in smooth accel
    averagexAccel += GetSmoothXAccel();
    averageyAccel += GetSmoothYAccel();
    accelCounter += 1;
  }

  void GetAverageAccel()
  {
    averagexAccel = averagexAccel/accelCounter;
    averageyAccel = averageyAccel/accelCounter;
  }

  void Loop()
  {
    GetAverageAccel();
    DoPosition();
    DoVelocity();
    DoTime();
  }

  void TestPosition()
  {
    AverageAccelCount();
    if (vex::timer::system() -  lastTime >= 1)
    {
      Loop();
      BrainUI::LogToScreen("X: " + Util::toString(GetSmoothXAccel()));
      BrainUI::LogToScreen("Y: " + Util::toString(currentyPos));
    }
  }

}
/*----------------------------------------------------------------------------*/
/*
    Module:       DriverControls.h                                                     
    Author:       Davis Teigeler                                            
    Created:      26 Jan 2022                                               
    Description:  Allows access to robots controls                              
*/
/*----------------------------------------------------------------------------*/

//Header Guard
#pragma once

#include "BrainUI.h"

namespace control
{

  /*
  * General control loop for the driver
  */
  extern void ControlBot();
  extern void MotorControl();
  extern void buttonPresses();

  extern int maxRPM;

  extern int MRvel;
  extern int MLvel;
}

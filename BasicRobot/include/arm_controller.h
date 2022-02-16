/*----------------------------------------------------------------------------*/
/*
    Module:       arm_controller.h                                                     
    Authors:      Zachary Spiggle, Davis Teigeler                                            
    Created:      1 Feb 2022                                               
    Description:  Declares functions used to control arm                            
*/
/*----------------------------------------------------------------------------*/

//Header Guard
#pragma once


namespace arm{

  extern int armSpeed;

  void Move();
  void moveArm();

}
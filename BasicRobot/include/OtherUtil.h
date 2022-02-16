/*----------------------------------------------------------------------------*/
/*
    Module:       OtherUtil.h                                                     
    Authors:      Zachary Spiggle, Davis Tiegeler                                      
    Created:      26 Jan 2022                                               
    Description:  Declares utility functions for other files                         
*/
/*----------------------------------------------------------------------------*/

//Header Guard
#pragma once


//Defines Utility functions missing in VEXcode version of C++
namespace Util
{
  float Lerp(float, float, float);

  std::string toString(int);
  std::string toString(float);
  std::string toString(double);
}
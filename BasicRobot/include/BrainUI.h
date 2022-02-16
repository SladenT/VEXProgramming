/*----------------------------------------------------------------------------*/
/*
    Module:       BrainUI.h                                                     
    Author:       Zachary Spiggle                                           
    Created:      3 Feb 2022                                               
    Description:  Allows messages to be sent and displayed on the brain screen                             
*/
/*----------------------------------------------------------------------------*/


//Header Guard
#pragma once

#include <string>

//Function used in other files to print to screen
namespace BrainUI
{
  void LogToScreen(std::string);
}
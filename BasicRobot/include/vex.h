/*----------------------------------------------------------------------------*/
/*
    Module:       vexx.h                                                     
    Author:       Vex Robotics                                              
    Created:      1 Feb 2019                                                
    Description:  Default header for V5 projects                               
*/
/*----------------------------------------------------------------------------*/
 

//Header Guard
#pragma once


//Include statements
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

//Define utility 
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
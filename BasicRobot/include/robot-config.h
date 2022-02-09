//Header Guard
#pragma once


using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor ML;
extern motor MR;
extern motor ML2;
extern motor MR2;
extern controller Controller1;
extern digital_out doutA;

extern bool AImode;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
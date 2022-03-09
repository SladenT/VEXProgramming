/*----------------------------------------------------------------------------*/
/*
    Module:       OtherUtil.cpp                                                
    Authors:      Davis Tiegeler, Zachary Spiggle                                 
    Created:      18 Jan 2022                                               
    Description:  Defines utility functions used by other parts of the program                     
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "sstream"

namespace Util
{
  // returns from a to b based on scalar t (0,1)
  float Lerp(float a, float b, float t)
  {
    return a + t*(b-a);
  }


  //Overloaded toString methods for int, float, and double since VexCode does not have one
  std::string toString(int k){
    std::stringstream ss;
    ss << k;
    std::string s;
    ss >> s;
    return s;
  }

  std::string toString(float k){
    std::stringstream ss;
    ss << k;
    std::string s;
    ss >> s;
    return s;
  }

  std::string toString(double k){
    std::stringstream ss;
    ss << k;
    std::string s;
    ss >> s;
    return s;
  }
}

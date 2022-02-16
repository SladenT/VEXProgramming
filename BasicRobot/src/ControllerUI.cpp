/*----------------------------------------------------------------------------*/
/*
    Module:       ControllerUI.cpp                                                
    Author:       Davis Tiegeler                            
    Created:      1 Feb 2022                                               
    Description:  Defines how UI operates on the Controller                     
*/
/*----------------------------------------------------------------------------*/

//Includes
#include "vex.h"
#include "robot-config.h"
#include "locale.h"
#include "ControllerUI.h"


namespace UI
{
  //using std::array;
 
  std::array<UIRow, 3> rows;
  // Controller UI Data
  UIElement aInit = {"A  ", "test"};
  UIElement bInit = {"B  ", "test"};
  std::array <UIElement, 2> e1 = {aInit, bInit};
  UIRow init = {0, e1};


  UIElement xInit = {"X  ", "test"};
  UIElement upInit = {"^  ", "test"};
  std::array <UIElement, 2> e2 = {xInit, upInit};
  UIRow init2 = {1, e2};

  UIElement YInit = {"Y  ", "test"};
  UIElement downInit = {"v  ", "test"};
  std::array <UIElement, 2> e3 = {YInit, downInit};
  UIRow init3 = {1, e3};

  void UpdateDisplay()
  {
    Controller1.Screen.clearScreen();
    for (int i = 0; i < rows.size(); i++)
    {
      Controller1.Screen.setCursor(i+1,1);
      Controller1.Screen.print(rows[i].elements[0].icon);
      Controller1.Screen.print(rows[i].elements[0].info);

      Controller1.Screen.setCursor(i+1,9);
      Controller1.Screen.print(rows[i].elements[1].icon);
      Controller1.Screen.print(rows[i].elements[1].info);
    }
  }
  void ArrangeRow(int index, UIRow colData)
  {
    if (index > rows.size())
    {
      return;
    }
    rows[index] = colData;
    UpdateDisplay();
  }
  
  
  void ArrangeUI(void* col)
  {
    rows[0] = ((struct UIRow *)col)[0];
    rows[1] = ((struct UIRow *)col)[1];
    rows[2] = ((struct UIRow *)col)[2];
    UpdateDisplay();
  }
  
}
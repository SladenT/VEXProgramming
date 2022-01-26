#include "vex.h"
#include "robot-config.h"
#include "locale.h"

namespace UI
{
  void DisplayControls()
  {
    char up[1];
    up[0] = '^';
    char down[1];
    down[0] = 'v';
    char right[1];
    right[0] = 187;
    char left[1];
    left[0] = 171;
    Controller1.Screen.setCursor(1,0);
    Controller1.Screen.print("A");
    Controller1.Screen.setCursor(2,0);
    Controller1.Screen.print("B");
    Controller1.Screen.setCursor(3,0);
    Controller1.Screen.print("X");
  }
}
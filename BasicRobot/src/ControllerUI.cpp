#include "vex.h"
#include "robot-config.h"
#include "locale.h"

namespace UI
{
  void DisplayControls()
  {
    Controller1.Screen.setCursor(0,0);
    Controller1.Screen.print("Wahahahah");
  }
}
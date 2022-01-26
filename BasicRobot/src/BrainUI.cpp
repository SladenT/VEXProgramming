#include "vex.h"
#include "robot-config.h"


using namespace vex;

namespace BrainUI
{
    int yPrintPos = 20; 
    int maxMessages = 10;
    int ySpacing = 20;

    std::string console = ""; //Will be used for console
    // Make this an array in the future so you can clear older messages, also can be sent to log file in future


    //Call this function with any string and it will print it to log, and automatically move to next line. Be careful because there is no overflow yet
    void LogToScreen(std::string str)
    {

      //Reset to account for overflow
      if (yPrintPos > 220){
        Brain.Screen.clearScreen();
        yPrintPos = 20;
      }

      console = ""; //Reset string before printing next line
      console.append(str);

      //This conversion is required for function
      const char * cString = console.c_str();

      Brain.Screen.printAt(20, yPrintPos, cString);
      yPrintPos += ySpacing;

    }
    


}

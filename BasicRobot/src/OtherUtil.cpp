#include "vex.h"
#include "sstream"
  namespace Util
  {
    // returns from a to b based on scalar t (0,1)
    float Lerp(float a, float b, float t)
    {
      return a + t*(b-a);
    }
  


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


  //Megolovania
  void TestSong()
  {
    // M10.spinFor(directionType::fwd, .12, timeUnits::sec, 195.77, velocityUnits::rpm); //D6
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 195.77, velocityUnits::rpm); //D6
    // M10.spinFor(directionType::fwd, .26, timeUnits::sec, 391.55, velocityUnits::rpm); //D7
    // M10.spinFor(directionType::rev, .26, timeUnits::sec, 293.333, velocityUnits::rpm); //A6

    // wait(.12, sec);

    // M10.spinFor(directionType::fwd, .12, timeUnits::sec, 276.87, velocityUnits::rpm); //G#

    // wait(.12, sec);
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 261.33, velocityUnits::rpm); //G6

    // wait(.12, sec);
    // M10.spinFor(directionType::fwd, .12, timeUnits::sec, 232.81, velocityUnits::rpm);

    // wait(.12, sec);
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 195.77, velocityUnits::rpm); //D6

    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 232.81, velocityUnits::rpm); //F

    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 261.33, velocityUnits::rpm); //G6
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 195.77, velocityUnits::rpm); //D6
    // M10.spinFor(directionType::fwd, .26, timeUnits::sec, 391.55, velocityUnits::rpm); //D7
    // M10.spinFor(directionType::rev, .26, timeUnits::sec, 293.333, velocityUnits::rpm); //A6

    // wait(.12, sec);

    // M10.spinFor(directionType::fwd, .12, timeUnits::sec, 276.87, velocityUnits::rpm); //G#

    // wait(.12, sec);
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 261.33, velocityUnits::rpm); //G6

    // wait(.12, sec);
    // M10.spinFor(directionType::fwd, .12, timeUnits::sec, 232.81, velocityUnits::rpm);

    // wait(.12, sec);
    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 195.77, velocityUnits::rpm); //D6

    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 232.81, velocityUnits::rpm); //F

    // M10.spinFor(directionType::rev, .12, timeUnits::sec, 261.33, velocityUnits::rpm); //G6


    // Note Reference
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 195.77, velocityUnits::rpm); //D6
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 207.41, velocityUnits::rpm); //D#
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 219.75, velocityUnits::rpm); //E
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 232.81, velocityUnits::rpm); //F
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 246.66, velocityUnits::rpm); //F#
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 261.33, velocityUnits::rpm); //G
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 276.87, velocityUnits::rpm); //G#
    // M10.spinFor(directionType::fwd, .4, timeUnits::sec, 293.333, velocityUnits::rpm); //A6
    // wait(.1, sec);
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 310.66, velocityUnits::rpm); //A#
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 329.08, velocityUnits::rpm); //B
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 348.83, velocityUnits::rpm); //C
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 369.57, velocityUnits::rpm); //C#
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 391.55, velocityUnits::rpm); //D
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 414.83, velocityUnits::rpm); //D#
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 439.5, velocityUnits::rpm); //E
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 465.63, velocityUnits::rpm); //F
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 493.32, velocityUnits::rpm); //F#
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 522.66, velocityUnits::rpm); //G
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 553.74, velocityUnits::rpm); //G#
    // M10.spinFor(directionType::fwd, 2, timeUnits::sec, 586.66, velocityUnits::rpm); //A7
  }
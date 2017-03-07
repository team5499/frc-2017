#pragma once

#include <WPILib.h>
#include "../Hardware.h"

using namespace team5499;

class Gearmech
{
private:

public:
  Gearmech();

  static void setRoller(double value)
  {
    hardware::intake_roller.Set(value);
  }

  static void setArm(double value)
  {
    hardware::intake_arm.Set(value);
  }
};
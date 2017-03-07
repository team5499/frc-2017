#pragma once

#include <WPILib.h>
#include "../Hardware.h"

using namespace team5499;

class Climber
{
public:
  Climber();

  static void climb()
  {
    hardware::climber.Set(1);
  }

  static void stop()
  {
    hardware::climber.Set(0);
  }
};
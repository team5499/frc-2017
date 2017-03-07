#pragma once

#include "../Hardware.h"

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
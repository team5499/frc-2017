#pragma once

#include "../Hardware.h"

namespace team5499
{
  class Climber
  {
  public:
    void climb(double speed)
    {
      hardware::climber.Set(speed);
    }
  };
}
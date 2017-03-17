#pragma once

#include "GearMech.h"
#include "Drivetrain.h"

namespace team5499
{
  class subsystems
  {
  public:
    static GearMech gearmech;
    static Drivetrain drivetrain;
    static Climber climber;
    static LED leds;
  };
}
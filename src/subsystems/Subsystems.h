#pragma once

#include "Drivetrain.h"
#include "Gearmech.h"
#include "Climber.h"
#include "Joysticks.h"

namespace team5499
{
  class subsystems
  {
  public:
    static Drivetrain drivetrain;
    static Gearmech gearmech;
    static Climber climber;
    static Joysticks joysticks;
  };
}
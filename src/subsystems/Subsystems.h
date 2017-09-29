#pragma once

#include "../RobotInit.h"

#include "../Reference.h"
#include "Drivetrain.h"
#include "Gearmech.h"
#include "Climber.h"
#include "Joysticks.h"
#include "Encoders.h"
#include "Angle.h"
#include "PID.h"

namespace team5499
{
  class subsystems
  {
  public:
    static Drivetrain drivetrain;
    static Gearmech gearmech;
    static Climber climber;
    static Joysticks joysticks;
    static Encoders encoders;
    static Angle angle;
    static PID leftpid;
    static PID rightpid;
    static PID anglepid;
  };
}
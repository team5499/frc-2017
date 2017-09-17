#include "Subsystems.h"

namespace team5499
{
  Drivetrain subsystems::drivetrain;
  Gearmech subsystems::gearmech;
  Climber subsystems::climber;
  Joysticks subsystems::joysticks;
  HandlePID subsystems::pid;

  bool subsystems::is_initialized = false;
}
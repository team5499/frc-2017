#include "Subsystems.h"

namespace team5499
{
  Drivetrain subsystems::drivetrain;
  Gearmech subsystems::gearmech;
  Climber subsystems::climber;
  Joysticks subsystems::joysticks;
  Encoders subsystems::encoders;
  Angle subsystems::angle;
  PID subsystems::leftpid(Reference::kP, Reference::kI, Reference::kD, 1);
  PID subsystems::rightpid(Reference::kP, Reference::kI, Reference::kD, 1);
  PID subsystems::anglepid(Reference::kAP, Reference::kAI, Reference::kAD, 1);
  LED subsystems::led;
}
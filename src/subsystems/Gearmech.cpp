#include "Gearmech.h"

namespace team5499
{
  void Gearmech::SetArm(double speed)
  {
    hardware::arm.Set(speed);
  }
  void Gearmech::SetRoller(double speed)
  {
    hardware::roller.Set(speed);
  }
}
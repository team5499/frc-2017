#include "Gearmech.h"

namespace team5499
{
  Gearmech::Gearmech()
  :
  roller(Reference::roller_port),
  arm(Reference::arm_port)
  {
    roller.SetInverted(true);
    arm.SetInverted(true);
    
    arm.SetVoltageRampRate(10);
  }
  void Gearmech::SetArm(double speed)
  {
    arm.Set(speed);
  }
  void Gearmech::SetRoller(double speed)
  {
    roller.Set(speed);
  }
  bool Gearmech::GearDetected()
  {
    if(roller.Get() != 0)
      return (roller.GetOutputCurrent() / roller.GetOutputVoltage() > 0.2);

    return false;
  }
}
#include "Gearmech.h"

namespace team5499
{
  Gearmech::Gearmech()
  :
  roller(Reference::roller_port),
  arm(Reference::arm_port),
  timer(),
  last(false)
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
    {
      if(roller.GetOutputCurrent() > 43.0)
      {
        std::cout << "Amperage ratio:" << (roller.GetOutputCurrent()) << std::endl;
        if(last)
        {
          std::cout << timer.Get() << std::endl;
          return (timer.Get() > 0.1);
        }
        else
        {
          last = true;
          timer.Start();
        }
      }
      else{
        last = false;
        timer.Reset();
      }
    }

    return false;
  }
}
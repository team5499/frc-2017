#include "GearMech.h"


namespace team5499
{
  void GearMech::SetSetpoint(double sp)
  {
    setpoint = sp;
  }

  void GearMech::handle()
  {
    static auto arm_pid = team5499::util::PID(0.25, 0, 0, 0);
    double pv = hardware::intake_pot.GetVoltage();
    double output = arm_pid(setpoint, pv);
    hardware::intake_arm.Set(output);
    std::cout << "PV: " << pv << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
  bool GearMech::seeGear()
  {
    return true;
  }
}
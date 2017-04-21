#include "GearMech.h"


namespace team5499
{
  void GearMech::SetRoller(double speed)
  {
    hardware::intake_roller.Set(speed);
  }
  void GearMech::SetArm(double speed)
  {
    hardware::intake_arm.Set(speed);
  }
  void GearMech::SetSetpoint(double sp)
  {
    setpoint = sp;
  }

  void GearMech::handle()
  {
    double sp = setpoint;
    double pv = hardware::intake_pot.GetVoltage();

    double error = (sp - pv);
    static double previous_error = error;
    static double previous_time = Timer::GetFPGATimestamp();
    double d_error = (error - previous_error) / (Timer::GetFPGATimestamp() - previous_time);

    double output = error * 0.325;

    previous_error = error;
    previous_time = Timer::GetFPGATimestamp();

    hardware::intake_arm.Set(output);
  }
  bool GearMech::seeGear()
  {
    return hardware::intake_roller.GetOutputCurrent() > 30.0;
  }
}

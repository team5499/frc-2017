#include "GearMech.h"


namespace team5499
{
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

    double output = error * 0.25;

    previous_error = error;
    previous_time = Timer::GetFPGATimestamp();

    hardware::intake_arm.Set(output);
  }
}
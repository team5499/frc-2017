#pragma once

#include "GenericCommand.h"
#include "../Hardware.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class TurnCommand : public GenericCommand
  {
  private:
    double m_Heading;

    double CalculateTurnOutput()
    {
      double sp = m_Heading;
      double pv = hardware::mxp_gyro.GetAngle();

      double error = (sp - pv);
      static double previous_error = error;
      static double previous_time = Timer::GetFPGATimestamp();
      double d_error = (error - previous_error) / (Timer::GetFPGATimestamp() - previous_time);

      double output = error * 0.3;

      previous_error = error;
      previous_time = Timer::GetFPGATimestamp();

      return output;
    }

  public:
    TurnCommand(double timeout, double heading)
      :
      GenericCommand(timeout),
      m_Heading(heading)
    {
    }

    void Start() override
    {
      GenericCommand::Start();
      hardware::mxp_gyro.ResetAngle();
    }

    void Step() override
    {
      static double previous = hardware::mxp_gyro.GetAngle();
      static double previous_time = Timer::GetFPGATimestamp();

      double rate = abs((hardware::mxp_gyro.GetAngle() - previous) / (Timer::GetFPGATimestamp() - previous_time));

      if(abs(m_Heading - hardware::mxp_gyro.GetAngle()) < 1.0 &&
         rate < 0.5)
      {
        Finished();
        return;
      }

      previous = hardware::mxp_gyro.GetAngle();
      previous_time = Timer::GetFPGATimestamp();

      double output = CalculateDriveOutput();
      double offset = CalculateTurnOutput();
      subsystems::drivetrain.Drive-offset, offset);
    }
  };
}
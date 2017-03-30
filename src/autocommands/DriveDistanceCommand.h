#pragma once

#include "GenericCommand.h"
#include "../Hardware.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class DriveDistanceCommand : public GenericCommand
  {
  private:
    double m_Distance;

    double CalculateDriveOutput()
    {
      double sp = m_Distance;
      double pv = hardware::drive_encoder.GetDistance();

      double error = (sp - pv);
      static double previous_error = error;
      static double previous_time = Timer::GetFPGATimestamp();
      double d_error = (error - previous_error) / (Timer::GetFPGATimestamp() - previous_time);

      double output = error * 0.012;

      if(abs(output) > 0.2)
        output = output > 0 ? 0.2 : -0.2;

      previous_error = error;
      previous_time = Timer::GetFPGATimestamp();

      return output;
    }

    double CalculateTurnOutput()
    {
      double sp = 0;
      double pv = hardware::mxp_gyro.GetAngle();

      double error = (sp - pv);
      static double previous_error = error;
      static double previous_time = Timer::GetFPGATimestamp();
      double d_error = (error - previous_error) / (Timer::GetFPGATimestamp() - previous_time);

      double output = error * 0.05;

      previous_error = error;
      previous_time = Timer::GetFPGATimestamp();

      return output;
    }

  public:
    DriveDistanceCommand(double timeout, double distance)
      :
      GenericCommand(timeout),
      m_Distance(distance)
    {
    }

    void Start() override
    {
      GenericCommand::Start();
      hardware::drive_encoder.Reset();
      hardware::mxp_gyro.ResetAngle();
    }

    void Step() override
    {
      static double previous = hardware::drive_encoder.GetDistance();
      static double previous_time = Timer::GetFPGATimestamp();

      double rate = abs((hardware::drive_encoder.GetDistance() - previous) / (Timer::GetFPGATimestamp() - previous_time));

      if(abs(m_Distance - hardware::drive_encoder.GetDistance()) < 2.0 &&
         rate < 1.0)
      {
        Finished();
        return;
      }

      previous = hardware::drive_encoder.GetDistance();
      previous_time = Timer::GetFPGATimestamp();

      double output = CalculateDriveOutput();
      double offset = CalculateTurnOutput();
      subsystems::drivetrain.Drive(output - offset, output + offset);
    }
  };
}
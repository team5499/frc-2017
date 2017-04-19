#pragma once

#include "GenericCommand.h"
#include "../Hardware.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class DeliverGearCenterCommand : public GenericCommand
  {
  private:
    double m_Distance;
    double f_Distance;
    double r_Distance;
    double i_down;
    double i_up;
    double i_timeout;
    double i_init_time;
    double ro_timeout;
    double ro_init_time;
    int state;

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
    DeliverGearCenterCommand(double timeout, double fdistance, double rdistance, double intakeDown, double intakeUp, double intakeTimeout, double rollerTimeout)
      :
      GenericCommand(timeout),
      f_Distance(fdistance),
      r_Distance(-rdistance),
      i_down(intakeDown),
      i_up(intakeUp),
      i_timeout(intakeTimeout),
      i_init_time(0),
      ro_timeout(rollerTimeout),
      ro_init_time(0),
      state(0)
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
      if(state == 0)
      {
          //Drive forward/set gear intake up
          
          subsystems::gearmech.SetSetpoint(i_up);
          
          m_Distance = f_Distance;
          
          static double previous = hardware::drive_encoder.GetDistance();
          static double previous_time = Timer::GetFPGATimestamp();

          double rate = abs((hardware::drive_encoder.GetDistance() - previous) / (Timer::GetFPGATimestamp() - previous_time));

          if(abs(m_Distance - hardware::drive_encoder.GetDistance()) < 2.0 &&
             rate < 1.0)
          {
            state = 1;
            hardware::drive_encoder.Reset();
            hardware::mxp_gyro.ResetAngle();
            i_init_time = Timer::GetFPGATimestamp();
            return;
          }

          previous = hardware::drive_encoder.GetDistance();
          previous_time = Timer::GetFPGATimestamp();

          double output = CalculateDriveOutput();
          double offset = CalculateTurnOutput();
          subsystems::drivetrain.Drive(output - offset, output + offset);
      }
      else if(state == 1)
      {
          //Put the gear intake down
          
          subsystems::gearmech.SetSetpoint(i_down);
          
          if((Timer::GetFPGATimestamp() - i_init_time) > i_timeout)
          {
              state = 2;
              return;
          }
          
      }
      else if(state == 2)
      {
          //Back up
          
          m_Distance = r_Distance;
          
          static double previous = hardware::drive_encoder.GetDistance();
          static double previous_time = Timer::GetFPGATimestamp();

          double rate = abs((hardware::drive_encoder.GetDistance() - previous) / (Timer::GetFPGATimestamp() - previous_time));

          if(abs(m_Distance - hardware::drive_encoder.GetDistance()) < 2.0 &&
             rate < 1.0)
          {
            state = 3;
            hardware::drive_encoder.Reset();
            hardware::mxp_gyro.ResetAngle();
            ro_init_time = Timer::GetFPGATimestamp();
            return;
          }

          previous = hardware::drive_encoder.GetDistance();
          previous_time = Timer::GetFPGATimestamp();

          double output = CalculateDriveOutput();
          double offset = CalculateTurnOutput();
          subsystems::drivetrain.Drive(output - offset, output + offset);
      }
      else if(state == 3)
      {
          //Check if the gear is still present in the intake
          
          subsystems::gearmech.SetRoller(1);
          
          if(subsystems::gearmech.seeGear())
          {
              subsystems::gearmech.SetRoller(0);
              state = 0;
              f_Distance = -r_Distance + 5;
              hardware::drive_encoder.Reset();
              hardware::mxp_gyro.ResetAngle();
              return;
          }
          else if((Timer::GetFPGATimestamp() - ro_init_time) > ro_timeout)
          {
              subsystems::gearmech.SetRoller(0);
              Finished();
              return;
          }
      }
    }
  };
}
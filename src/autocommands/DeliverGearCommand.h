#pragma once

#include "GenericCommand.h"
#include "../Hardware.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class DeliverGearCommand : public GenericCommand
  {
  private:
    double m_Distance;
    double m_Heading;
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

    double CalculateTurnOutputDrive()
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

    double CalculateTurnOutput()
    {
      double sp = m_Heading;
      double pv = hardware::mxp_gyro.GetAngle();

      double error = (sp - pv);
      static double previous_error = error;
      static double previous_time = Timer::GetFPGATimestamp();
      double d_error = (error - previous_error) / (Timer::GetFPGATimestamp() - previous_time);

      double output = error * 0.0065 + d_error * 0.0001;


      std::cout << "Gyro: "  << sp << std::endl;
      std::cout << "Output: "  << output << std::endl;

      previous_error = error;
      previous_time = Timer::GetFPGATimestamp();

      return output;
    }

  public:
    DeliverGearCommand(double timeout)
      :
      GenericCommand(timeout)
    {
      m_Distance = 0;
      m_Heading = 0;
      state = 0;
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
          m_Distance = 0;
        subsystems::gearmech.SetRoller(0.6);
        if(subsystems::gearmech.seeGear())
        {
            state = 1;
            subsystems::gearmech.SetRoller(0);
        }
        else
        {
            subsystems::gearmech.SetRoller(0);
            Finished();
            return;
        }
      }
      else if(state == 1)
      {

        m_Distance = 0;
        m_Heading = 2;

        static double previous = hardware::mxp_gyro.GetAngle();
        static double previous_time = Timer::GetFPGATimestamp();

        double rate = abs((hardware::mxp_gyro.GetAngle() - previous) / (Timer::GetFPGATimestamp() - previous_time));

        previous = hardware::mxp_gyro.GetAngle();
        previous_time = Timer::GetFPGATimestamp();

        double offset = CalculateTurnOutput();
        subsystems::drivetrain.Drive(-offset, offset);

        if(abs(m_Heading - hardware::mxp_gyro.GetAngle()) < 1.0 &&
            rate < 0.5)
        {
            state++;
            hardware::drive_encoder.Reset();
            hardware::mxp_gyro.ResetAngle();
        }
      }
      else if(state == 2)
      {
        m_Distance = 35;

        static double previous = hardware::drive_encoder.GetDistance();
        static double previous_time = Timer::GetFPGATimestamp();

        double rate = abs((hardware::drive_encoder.GetDistance() - previous) / (Timer::GetFPGATimestamp() - previous_time));

        previous = hardware::drive_encoder.GetDistance();
        previous_time = Timer::GetFPGATimestamp();

        double output = CalculateDriveOutput();
        double offset = CalculateTurnOutputDrive();
        subsystems::drivetrain.Drive(output - offset, output + offset);

        if(abs(m_Distance - hardware::drive_encoder.GetDistance()) < 2.0 &&
            rate < 1.0)
        {
            state++;
            hardware::drive_encoder.Reset();
            hardware::mxp_gyro.ResetAngle();
        }
      }
      else if(state == 3)
      {
        subsystems::gearmech.SetSetpoint(2);

        m_Distance = -30;

        static double previous = hardware::drive_encoder.GetDistance();
        static double previous_time = Timer::GetFPGATimestamp();

        double rate = abs((hardware::drive_encoder.GetDistance() - previous) / (Timer::GetFPGATimestamp() - previous_time));

        previous = hardware::drive_encoder.GetDistance();
        previous_time = Timer::GetFPGATimestamp();

        double output = CalculateDriveOutput();
        double offset = CalculateTurnOutputDrive();
        subsystems::drivetrain.Drive(output - offset, output + offset);

        if(abs(m_Distance - hardware::drive_encoder.GetDistance()) < 2.0 &&
            rate < 1.0)
        {
            state++;
            hardware::drive_encoder.Reset();
            hardware::mxp_gyro.ResetAngle();
        }
      }
      else
      {
        subsystems::gearmech.SetSetpoint(0.75);
        state == 0;
      }
    }
  };
}
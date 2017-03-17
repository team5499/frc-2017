#include "Robot.h"

namespace team5499
{
  auto autoController = make_auto_controller(
    make_auto_routine(
      IntakeSetpointCommand(0.1, 0.75),
      DriveDistanceCommand(5, 6 * 12),
      IntakeSetpointCommand(1, 2),
      DriveDistanceCommand(3, -4 * 12)
    )
  );

  Robot::Robot()
  {
  }

  void Robot::RobotInit()
  {
    hardware::drive_right1.SetInverted(true);
    hardware::drive_right2.SetInverted(true);

    hardware::drive_left1.SetVoltageRampRate(10);
    hardware::drive_left2.SetVoltageRampRate(10);
    hardware::drive_right1.SetVoltageRampRate(10);
    hardware::drive_right2.SetVoltageRampRate(10);

    hardware::intake_arm.SetInverted(true);

    hardware::climber.SetInverted(true);

    hardware::mxp_display.SetBanner("5499");
    hardware::mxp_display.DisplayBanner();

    hardware::drive_encoder.SetDistancePerPulse(0.0490625); // 4 * pi / 256
    hardware::mxp_gyro.BeginCalibration();
  }

  void Robot::RobotPeriodic()
  {
  }

  void Robot::DisabledInit()
  {
//    std::cout << "Mode: " << autoController.GetCurrentRoutineName() << std::endl;
    hardware::leds.disable();
  }

  void Robot::DisabledPeriodic()
  {
  }

  void Robot::AutonomousInit()
  {
    autoController.Reset();
    hardware::mxp_gyro.FinalizeCalibration();
  }

  void Robot::AutonomousPeriodic()
  {
    autoController.Step();
    subsystems::gearmech.handle();
  }

  void Robot::TeleopInit()
  {
    hardware::mxp_gyro.FinalizeCalibration();
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Step();
  }
}
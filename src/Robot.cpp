#include "Robot.h"

namespace team5499
{
  auto centerAutoController = make_auto_controller(
    make_auto_routine(
      IntakeSetpointCommand(0.1, 0.75),
      DriveDistanceCommand(4, 6 * 12),
      IntakeSetpointCommand(1, 2),
      DriveDistanceCommand(3, -4 * 12)
    )
  );

  auto leftAutoController = make_auto_controller(
    make_auto_routine(
      IntakeSetpointCommand(0.1, 0.75),
      DriveDistanceCommand(4, 92),
      TurnCommand(2, 60),
      DriveDistanceCommand(4, 87),
      IntakeSetpointCommand(1, 2),
      DriveDistanceCommand(3, -4 * 12)
    )
  );

  auto rightAutoController = make_auto_controller(
    make_auto_routine(
      IntakeSetpointCommand(0.1, 0.75),
      DriveDistanceCommand(4, 92),
      TurnCommand(2, 60),
      DriveDistanceCommand(4, 87),
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
    hardware::mxp_gyro.BeginCalibration();
  }

  void Robot::DisabledPeriodic()
  {
    static bool previousAutoButton = false;
    if(!previousAutoButton && hardware::throttle.GetRawButton(1))
    {
      if(autoIndex++ == 3)
        autoIndex = 0;

      switch(autoIndex)
      {
        case 0:
          std::cout << "Center" << std::endl;
          break;
        case 1:
          std::cout << "Left" << std::endl;
          break;
        case 2:
          std::cout << "Right" << std::endl;
          break;
      }
    }
    previousAutoButton = hardware::throttle.GetRawButton(0);
  }

  void Robot::AutonomousInit()
  {
    switch(autoIndex)
    {
      case 0:
        centerAutoController.Reset();
        break;
      case 1:
        leftAutoController.Reset();
        break;
      case 2:
        rightAutoController.Reset();
        break;
    }
    hardware::mxp_gyro.FinalizeCalibration();
  }

  void Robot::AutonomousPeriodic()
  {
    switch(autoIndex)
    {
      case 0:
        centerAutoController.Step();
        break;
      case 1:
        leftAutoController.Step();
        break;
      case 2:
        rightAutoController.Step();
        break;
    }
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
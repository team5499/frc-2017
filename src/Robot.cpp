#include "Robot.h"

namespace team5499
{
  const double ARM_UP_POSITION = 0.915;
  const double ARM_DOWN_POSITION = 2.78;

  auto centerAutoController = make_auto_controller(
    make_auto_routine(
      DriveDistanceCommand(4, 82),
      IntakeMoveCommand(1, 0.4),
      DriveDistanceCommand(3, -4 * 12),
      IntakeMoveCommand(1, -0.4),
      IntakeMoveCommand(0.1, 0),
      TurnCommand(1, -90),
      DriveDistanceCommand(2, 65),
      TurnCommand(1, 90),
      DriveDistanceCommand(6, 200)
    )
  );

  auto leftAutoController = make_auto_controller(
    make_auto_routine(
      DriveDistanceCommand(4, 72),
      TurnCommand(2, 60),
      DriveDistanceCommand(4, 72),
      IntakeMoveCommand(1, 0.4),
      DriveDistanceCommand(3, -4 * 12),
      IntakeMoveCommand(1, -0.4),
      IntakeMoveCommand(0.1, 0),
      TurnCommand(2, -60),
      DriveDistanceCommand(6, 120)
    )
  );

  auto rightAutoController = make_auto_controller(
    make_auto_routine(
      DriveDistanceCommand(4, 72),
      TurnCommand(2, -60),
      DriveDistanceCommand(4, 72),
      IntakeMoveCommand(1, 0.4),
      DriveDistanceCommand(3, -4 * 12),
      IntakeMoveCommand(1, -0.4),
      IntakeMoveCommand(0.1, 0),
      TurnCommand(2, 60),
      DriveDistanceCommand(6, 120)
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

    //CameraServer::GetInstance()->StartAutomaticCapture();
  }

  void Robot::RobotPeriodic()
  {
  }

  void Robot::DisabledInit()
  {
//    std::cout << "Mode: " << autoController.GetCurrentRoutineName() << std::endl;
//    hardware::leds.disable();
    hardware::mxp_gyro.BeginCalibration();
  }

  void Robot::DisabledPeriodic()
  {
    static bool previousAutoButton = false;
    if(!previousAutoButton && hardware::throttle.GetRawButton(1))
    {
      if(++autoIndex == 3)
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
//    std::cout << hardware::intake_pot.GetVoltage() << std::endl;
    previousAutoButton = hardware::throttle.GetRawButton(1);
  }

  void Robot::AutonomousInit()
  {
    subsystems::gearmech.SetInitialPV(hardware::intake_pot.GetVoltage());
    hardware::mxp_gyro.FinalizeCalibration();
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
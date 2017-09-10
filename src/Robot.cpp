#include "Robot.h"

namespace team5499
{

  Robot::Robot()
  {
  }

  void Robot::RobotInit()
  {
    hardware::drive_right1.SetInverted(true);
    hardware::drive_right2.SetInverted(true);

    hardware::drive_left1.SetVoltageRampRate(30);
    hardware::drive_left2.SetVoltageRampRate(30);
    hardware::drive_right1.SetVoltageRampRate(30);
    hardware::drive_right2.SetVoltageRampRate(30);
  }

  void Robot::RobotPeriodic()
  {
  }

  void Robot::DisabledInit()
  {
  }

  void Robot::DisabledPeriodic()
  {
  }

  void Robot::AutonomousInit()
  {
  }

  void Robot::AutonomousPeriodic()
  {
  }

  void Robot::TeleopInit()
  {
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Step();
  }
}
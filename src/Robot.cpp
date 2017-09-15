#include "Robot.h"

namespace team5499
{

  Robot::Robot()
  {
  }

  void Robot::RobotInit()
  {
  }

  void Robot::RobotPeriodic()
  {
  }

  void Robot::DisabledInit()
  {
  }

  void Robot::DisabledPeriodic()
  {
    subsystems::joysticks.handleConfig();
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
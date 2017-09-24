#include "RobotInit.h"
#include "Robot.h"

namespace team5499
{

  OperatorController Robot::operatorController;
  AutoController Robot::autoController;

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
  }

  void Robot::AutonomousInit()
  {
  }

  void Robot::AutonomousPeriodic()
  {
    autoController.Handle();
  }

  void Robot::TeleopInit()
  {
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Handle();
  }
}
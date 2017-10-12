#include "RobotInit.h"
#include "Robot.h"
#include <unistd.h>
#include <math.h>

namespace team5499
{

  Robot::Robot()
  :
  operatorController(),
  autoController()
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
    autoController.Start();
  }

  void Robot::AutonomousPeriodic()
  {
    autoController.Handle();
  }

  void Robot::TeleopInit()
  {
    operatorController.Start();
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Handle();
  }
}
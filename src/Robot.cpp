#include "RobotInit.h"
#include "Robot.h"
#include <unistd.h>

namespace team5499
{

  OperatorController Robot::operatorController;
  AutoController Robot::autoController;

  Robot::Robot()
  {
  }

  void Robot::RobotInit()
  {
    Reference::updateVariables();
    subsystems::encoders.reset();
  }

  void Robot::RobotPeriodic()
  {
    subsystems::angle.handle(subsystems::encoders.getLeftDistance(), subsystems::encoders.getRightDistance());
  }

  void Robot::DisabledInit()
  {
    Reference::updateVariables();
    subsystems::encoders.reset();
    subsystems::angle.reset();
    autoController.reset();
  }

  void Robot::DisabledPeriodic()
  {
    subsystems::encoders.reset();
    subsystems::angle.reset();
  }

  void Robot::AutonomousInit()
  {
    Reference::updateVariables();
    autoController.Start();
  }

  void Robot::AutonomousPeriodic()
  {
    autoController.Handle();
  }

  void Robot::TeleopInit()
  {
    Reference::updateVariables();
    operatorController.Start();
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Handle();
  }
}
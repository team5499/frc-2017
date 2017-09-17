#include "Robot.h"

namespace team5499
{

  Robot::Robot()
  {
  }

  void Robot::RobotInit()
  {
    subsystems::pid.left_encoder.SetDistancePerPulse(0.04908738438);
    subsystems::pid.right_encoder.SetDistancePerPulse(0.04908738438);

    subsystems::pid.left_controller.SetOutputRange(-1, 1);
    subsystems::pid.right_controller.SetOutputRange(-1, 1);

    subsystems::pid.left_controller.SetToleranceBuffer(20);
    subsystems::pid.right_controller.SetToleranceBuffer(20);
  }

  void Robot::RobotPeriodic()
  {

  }

  void Robot::DisabledInit()
  {
  }

  void Robot::DisabledPeriodic()
  {
    std::cout << subsystems::pid.left_encoder.Get() << ":" << subsystems::pid.left_encoder.GetDistance() << std::endl;
  }

  void Robot::AutonomousInit()
  {
    subsystems::pid.left_encoder.Reset();
    subsystems::pid.right_encoder.Reset();
  }

  void Robot::AutonomousPeriodic()
  {
    autoController.Step();
  }

  void Robot::TeleopInit()
  {
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Step();
  }
}
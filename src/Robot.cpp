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
    subsystems::encoders.reset();
    subsystems::led.setRGB(0, 0, 0);
  }

  void Robot::RobotPeriodic()
  {
    subsystems::angle.handle(subsystems::encoders.getLeftDistance(), subsystems::encoders.getRightDistance());
    subsystems::led.handle();

    //std::cout << subsystems::encoders.getLeftDistance() << ":" << subsystems::encoders.getRightDistance() << std::endl;
  }

  void Robot::DisabledInit()
  {
    Reference::initPIDVariables();
    subsystems::leftpid.setPID(Reference::kP, Reference::kI, Reference::kD);
    subsystems::rightpid.setPID(Reference::kP, Reference::kI, Reference::kD);
    subsystems::anglepid.setPID(Reference::kAP, Reference::kAI, Reference::kAD);
    subsystems::encoders.reset();
    subsystems::angle.reset();
    autoController.reset();

  }

  void Robot::DisabledPeriodic()
  {
    Reference::initPIDVariables();
    subsystems::leftpid.setPID(Reference::kP, Reference::kI, Reference::kD);
    subsystems::rightpid.setPID(Reference::kP, Reference::kI, Reference::kD);
    subsystems::anglepid.setPID(Reference::kAP, Reference::kAI, Reference::kAD);
    subsystems::encoders.reset();
    subsystems::angle.reset();
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
    SmartDashboard::PutNumber("time_running", true);
  }

  void Robot::TeleopPeriodic()
  {
    operatorController.Handle();
  }
}
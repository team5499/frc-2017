#include "Robot.h"

Robot::Robot()
{
  std::cout << "Iterative Robot Framework initialized." << std::endl;
}

void Robot::RobotInit()
{
  team5499::hardware::drive_left1.SetInverted(true);
  team5499::hardware::drive_left2.SetInverted(true);

  team5499::hardware::drive_left1.SetVoltageRampRate(10);
  team5499::hardware::drive_left2.SetVoltageRampRate(10);
  team5499::hardware::drive_right1.SetVoltageRampRate(10);
  team5499::hardware::drive_right2.SetVoltageRampRate(10);

  team5499::hardware::intake_arm.SetInverted(true);

  team5499::hardware::mxp_display.SetBanner("5499");
  team5499::hardware::mxp_display.DisplayBanner();
  std::cout << "RobotInit complete" << std::endl;
}

void Robot::RobotPeriodic()
{

}

void Robot::DisabledInit()
{
  std::cout << "DisabledInit" << std::endl;
}

void Robot::DisabledPeriodic()
{
  //hardware::gyro.HandleCalibration();
}

void Robot::AutonomousInit()
{
  //hardware::gyro.FinalizeCalibration();
  //autoController.start();
  std::cout << "AutonomousInit" << std::endl;
}

void Robot::AutonomousPeriodic()
{
  //autoController.handle();
}

void Robot::TeleopInit()
{
  std::cout << "TeleopInit" << std::endl;
  operatorController.start();
}

void Robot::TeleopPeriodic()
{
  operatorController.handle();
}
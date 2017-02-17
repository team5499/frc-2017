#include "Robot.h"

Robot::Robot()
        :
        reference(), hardware(),
        operatorController(reference, hardware)
{
  std::cout << "Iterative Robot Framework initialized." << std::endl;
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
  operatorController.handle();
}

START_ROBOT_CLASS(Robot)
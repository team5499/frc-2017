#include "Robot.h"

Robot::Robot()
    :
    ref(),
    hardware(),
    operatorController(&ref, &hardware)
{
    std::cout << "Iterative Robot Framework initialized." << std::endl;
}
void Robot::DisabledInit() {

}
void Robot::DisabledPeriodic() {

}

void Robot::AutonomousInit() {
}
void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {

}
void Robot::TeleopPeriodic() {

}

START_ROBOT_CLASS(Robot)
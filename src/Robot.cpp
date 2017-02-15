#include "Robot.h"

Robot::Robot()
    :
    ref(),
    hardware(),
    operatorController(&ref, &hardware),
    autoController(&ref, &hardware)
{
    std::cout << "Iterative Robot Framework initialized." << std::endl;
}
void Robot::DisabledInit() {

}
void Robot::DisabledPeriodic() {
    hardware.gyroscope.HandleCalibration();
}

void Robot::AutonomousInit() {
    hardware.gyroscope.FinalizeCalibration();
    autoController.start();

}
void Robot::AutonomousPeriodic() {
    autoController.handle();
}

void Robot::TeleopInit() {
    operatorController.start();
}
void Robot::TeleopPeriodic() {
    operatorController.handle();
}

START_ROBOT_CLASS(Robot)
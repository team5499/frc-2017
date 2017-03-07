#include "Robot.h"

Robot::Robot()
    :
    operatorController()
{
    std::cout << "Iterative Robot Framework initialized." << std::endl;
}
void Robot::DisabledInit() {

}
void Robot::DisabledPeriodic() {
    //hardware::gyro.HandleCalibration();
}

void Robot::AutonomousInit() {
    //hardware::gyro.FinalizeCalibration();
    //autoController.start();

}
void Robot::AutonomousPeriodic() {
    //autoController.handle();
}

void Robot::TeleopInit() {
    operatorController.start();
}
void Robot::TeleopPeriodic() {
    operatorController.handle();
}

START_ROBOT_CLASS(Robot)
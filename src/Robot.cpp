#include "Robot.h"

Robot::Robot()
    :
    operatorController(),
    autoController()
{
    Hardware::angleController.SetAbsoluteTolerance(Reference::kEa);
    Hardware::angleController.SetToleranceBuffer(Reference::toleranceBuffer);
    Hardware::distanceController.SetAbsoluteTolerance(Reference::kEd);
    Hardware::distanceController.SetToleranceBuffer(Reference::toleranceBuffer);
    std::cout << "Iterative Robot Framework initialized." << std::endl;
}
void Robot::DisabledInit() {
    Hardware::gyroscope.BeginCalibration();
}
void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
    Hardware::gyroscope.FinalizeCalibration();
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
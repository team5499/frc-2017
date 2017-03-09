#include "Robot.h"

Robot::Robot()
    :
    gyroscope()
    //ref(),
    //hardware(),
    //operatorController(&ref, &hardware),
    //autoController(&ref, &hardware)
{
    std::cout << "Iterative Robot Framework initialized." << std::endl;
    gyroscope.BeginCalibration();
}
void Robot::DisabledInit() {

}
void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
    gyroscope.FinalizeCalibration();
    

}
void Robot::AutonomousPeriodic() {
   frc::SmartDashboard::PutNumber("gyro angle", gyroscope.GetAngle());
}

void Robot::TeleopInit() {
    
}
void Robot::TeleopPeriodic() {
    
}

START_ROBOT_CLASS(Robot)
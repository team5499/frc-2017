#include"Robot.h"
#include"RobotInit.h"

namespace team5499 {
    OperatorController Robot::OperatorController;
    AutoController Robot::AutoController;

    Robot() {}

    void Robot::RobotInit() {
        
    }

    void Robot::RobotPeriodic() {

    }

    void Robot::DisabledInit() {

    }

    void Robot::DisabledPeriodic() {

    }

    void Robot::TeleopInit() {
        operatorController.Start();        
    }

    void Robot::TeleopPeriodic() {
        operatorController.Handle();
    }

    void Robot::AutonomousInit() {

    }
    
    void Robot::AutonomousPeriodic() {
    }

}

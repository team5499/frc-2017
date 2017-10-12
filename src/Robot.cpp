#include "Robot.h"
#include "RobotInit.h"

namespace team5499 {
    OperatorController Robot::operatorController;
    AutoController Robot::autoController;

    Robot::Robot() {};

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
        autoController.Start();
    }
    
    void Robot::AutonomousPeriodic() {
        autoController.Handle();
    }

}

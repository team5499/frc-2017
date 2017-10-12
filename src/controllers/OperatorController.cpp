#include "OperatorController.h"

namespace team5499 {

    void OperatorController::Start() {

    }

    void OperatorController::Handle() {
        //drivetrain
        double left = subsystems::joysticks.getLeftStick() + subsystems::joysticks.getRightStick();
        double right = subsystems::joysticks.getLeftStick() - subsystems::joysticks.getRightStick();
        subsystems::driveTrain.drive(left, right);

        // Climber
        if(subsystems::joysticks.getClimb()) {
            subsystems::climber.climb(Reference::climb_speed);
        }

        // arm
        subsystems::gearMech.SetArm(subsystems::joysticks.getArm());

        // Roller
        if(subsystems::joysticks.getIntake() == 0) {
            subsystems::gearMech.intake();
        } else if(subsystems::joysticks.getIntake() == 1) {
            subsystems::gearMech.outtake();
        }
    }
    
}
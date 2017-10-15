#include "OperatorController.h"

namespace team5499 {

    void OperatorController::Start() {
        timer.Start();
        random = false;
    }

    void OperatorController::Handle() {
        millis = timer.Get() * 1000;
        bool slow = subsystems::joysticks.getSlow();
        //drivetrain
        double left = 0;
        double right = 0;

        left = subsystems::joysticks.getLeftStick() * 0.7 - subsystems::joysticks.getRightStick() * 0.3;
        right = subsystems::joysticks.getLeftStick() * 0.7 + subsystems::joysticks.getRightStick() * 0.3;
        // std::cout<<"Left: "<<left<<", Right: "<<right<<std::endl;
        
        if(slow) {
            left *= 0.2;
            right *= 0.2;
        }
        subsystems::driveTrain.drive(left, right);

        // Climber
        if(subsystems::joysticks.getClimb()) {
            subsystems::climber.climb(Reference::climb_speed);
            
            if(millis % 100 == 0) {

            
             if(random){
                 subsystems::led.setRGB(0, 256, 0);
                  random = !random;
             } else {
                  subsystems::led.setRGB(256, 0, 0);
                   random = !random;
                }
            }

        } else if(subsystems::joysticks.getReverseClimb()) {
            subsystems::climber.climb(-Reference::climb_speed);

            if(millis % 100 == 0) { 
                if(random){
                    subsystems::led.setRGB(11, 51, 17);
                    random = !random;
                } else {
                subsystems::led.setRGB(256, 0, 0);
                    random = !random;
                }
            }
        } else{
             subsystems::climber.stop();
             subsystems::led.setRGB(256, 256, 256);
        }
        
        // arm
        subsystems::gearMech.SetArm(-subsystems::joysticks.getArm());

        // Roller
        if(subsystems::joysticks.getIntake() == 0) {
            subsystems::gearMech.intake();
        } else if(subsystems::joysticks.getIntake() == 1) {
            subsystems::gearMech.outtake();
        } else {
            subsystems::gearMech.stopRoll();
        }
    }
    
}
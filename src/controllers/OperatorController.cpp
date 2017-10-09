#include "OperatorController.h"

namespace team5499 {

    void OperatorController::Start() {

    }

    void OperatorController::Handle() {
        subsystems::driveTrain.drive(subsystems::joysticks.getLeftStick(), subsystems::joysticks.getLeftStick());
    }
    
}
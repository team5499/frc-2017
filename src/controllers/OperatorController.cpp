#include "OperatorController.h"
#include <iostream>

namespace team5499 {
    Robot::DriveTrain.drive(subsystems::joysticks.getLeftStick() - subsystems::joysticks.getRightStick(), subsystems::joysticks.getLeftStick() + subsystems::joysticks.getRightStick());
    
}
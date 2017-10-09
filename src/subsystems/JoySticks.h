#pragma once

#include "WPILib.h"
#include <iostream>
#include "Joystick.h"
#include "XboxController.h"
#include "../Reference.h"


namespace team5499 {
    class JoySticks {
    private:
        XboxController driver, coDriver;
    public:
        JoySticks();
        
        double getLeftStick();
        double getRightStick();
        bool getClimb();
        int getIntake();
        double getArm();

    };
}
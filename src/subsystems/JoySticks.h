#pragma once

#include "WPILib.h"
#include <iostream>
#include "XboxController.h"
#include "../Reference.h"


namespace team5499 {
    class JoySticks {
    private:
        XboxController driver;
        XboxController coDriver;
    public:
        JoySticks();
        
        float getLeftStick();
        float getRightStick();
        bool getClimb();
        int getIntake();
        double getArm();

    };
}
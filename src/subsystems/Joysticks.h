#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

namespace team5499
{
    class Joysticks
    {
    private:
        bool prev;
        int config;
        XboxController xbox;
        XboxController driver;
        Joystick throttle;
        Joystick wheel;
    public:
        Joysticks();
        void handleConfig();
        double getLeftValue();
        double getRightValue();
        double getClimberValue();
        double getRollerValue();
        double getArmValue();
    };
}
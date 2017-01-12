#pragma once
#include <WPILib.h>

class Reference {
    public:
        // PID
        const double kP = 0.01;
        const double kI = 0.0;
        const double kD = 0.0;

        // Joysticks
        const int wheel = 1;
        const int throttle = 0;
};
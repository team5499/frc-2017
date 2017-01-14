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

        // Talon Ports
        const int left1id = 0;
        const int left2id = 1;
        const int right1id = 2;
        const int right2id = 3;
};
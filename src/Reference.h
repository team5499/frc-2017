#pragma once
#include <WPILib.h>

class Reference {
    public:
        // PID
        const double kP = 0.01;
        const double kI = 0.0;
        const double kD = 0.0;

        const double kVd = 10;
        const double kVa = 3;
        const double kEd = 20;
        const double kEa = 1;

        const int toleranceBuffer = 4;

        // Joysticks
        const int wheel = 1;
        const int throttle = 0;
        const double wheeldeadzone = 0.05;
        const double throttledeadzone = 0.05;
        const int climbbutton = 4;

        // Drivetrain Talon Ports
        const int left1id = 0;
        const int left2id = 1;
        const int right1id = 2;
        const int right2id = 3;

        // Climber
        const int motorid = 4;

        // Sensors
        const uint32_t gyroport = 0;
        const int lEncoderPortA = 0;
        const int lEncoderPortB = 1;
        const int rEncoderPortA = 2;
        const int rEncoderPortB = 3;
};
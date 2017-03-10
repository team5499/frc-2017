#pragma once
#include <WPILib.h>

class Reference {
    public:
        // PID
        static const double kP;
        static const double kI;
        static const double kD;

        static const double kVd;
        static const double kVa;
        static const double kEd;
        static const double kEa;

        static const int toleranceBuffer;

        // Joysticks
        static const int wheel;
        static const int throttle;
        static const int xbox;
        static const double wheeldeadzone;
        static const double throttledeadzone;
        static const int climbbutton;

        // Drivetrain Talon Ports
        static const int left1id;
        static const int left2id;
        static const int right1id;
        static const int right2id;

        // Climber
        static const int motorid;

        //Gearmech
        static const int rollerid;
        static const int armid;

        // Sensors
        static const uint32_t gyroport;
        static const int lEncoderPortA;
        static const int lEncoderPortB;
        static const int rEncoderPortA;
        static const int rEncoderPortB;
};
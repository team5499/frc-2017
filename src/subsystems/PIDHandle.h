#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include <team1538/CowAlphaNum.h>
#include <team1538/CowGyro.h>
#include "ManualPID.h"
#include "../Reference.h"

namespace team5499
{
    class PIDHandle
    {
    private:
        double setPointLeft;
        double setPointRight;
        frc::PIDController left_side_controller;
        ManualPID drive_left, drive_right;
        frc::Encoder left_side, right_side;
    public:
        PIDHandle();
        void resetEncoders();
        /*
        void enable();
        double getSetPoint();
        void setLeftSetPoint(double set);
        void setRightSetPoint(double set);
        void step();
        */
        int getRawLeftValue();
        int getRawRightValue();
    };
}
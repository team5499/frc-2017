#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

namespace team5499
{
    class Gearmech
    {
    private:
        CANTalon roller;
        CANTalon arm;

        Timer timer;
        bool last;
    public:
        Gearmech();
        void SetArm(double speed);
        void SetRoller(double speed);
        bool GearDetected();
    };
}
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
    public:
        Gearmech();
        void SetArm(double speed);
        void SetRoller(double speed);
    };
}
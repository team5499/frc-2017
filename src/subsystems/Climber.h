#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

namespace team5499
{
    class Climber
    {
    private:
        CANTalon climber_left, climber_right;
    public:
        Climber();
        void SetClimber(double speed);
    };
}
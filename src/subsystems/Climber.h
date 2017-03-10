#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Climber
{
    private:
        CANTalon motor;

    public:
        Climber();
        void setSpeed(double power);
};
#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Climber
{
    private:
        Reference* r;
        CANTalon motor;

    public:
        Climber(Reference* ref);
        void setSpeed(double power);
};
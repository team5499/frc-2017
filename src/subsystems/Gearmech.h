#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Gearmech
{
    private:

        CANTalon arm;
        CANTalon roller;

    public:

        Gearmech();
        void setArm(double speed);
        void setRoller(double speed);
};
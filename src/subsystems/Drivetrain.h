#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Drivetrain
{
    private:

        CANTalon left1;
        CANTalon left2;
        CANTalon right1;
        CANTalon right2;

    public:

        Drivetrain();
        void driveLR(double left, double right);
};
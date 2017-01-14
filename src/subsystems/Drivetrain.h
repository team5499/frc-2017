#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"

class Drivetrain
{
    private:
        Reference* r;
        Hardware* h;

        CANTalon* left1;
        CANTalon* left2;
        CANTalon* right1;
        CANTalon* right2;

    public:
        typedef enum
        {
            LOW,
            HIGH
        } ShiftState;
        Drivetrain(Reference* ref, Hardware* hardware);
        void driveLR(double left, double right);
        void shift(ShiftState state);
};
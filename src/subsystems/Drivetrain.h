#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Drivetrain
{
    private:
        Reference* r;

        CANTalon left1;
        CANTalon left2;
        CANTalon right1;
        CANTalon right2;

        frc::Solenoid lshift;
        frc::Solenoid rshift;

    public:
        typedef enum
        {
            LOW,
            HIGH
        } ShiftState;
        ShiftState currentShift;
        Drivetrain(Reference* ref);
        void driveLR(double left, double right);
        void shift(ShiftState state);
};
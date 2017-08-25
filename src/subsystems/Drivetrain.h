#pragma once
#include <CANTalon.h>
#include <iostream>

#include "Reference.h"

class Drivetrain
{
private:
    CANTalon drive_left1;
    CANTalon drive_left2;
    CANTalon drive_right1;
    CANTalon drive_right2;
public:
    Drivetrain();
    void driveLR(double left, double right);
};
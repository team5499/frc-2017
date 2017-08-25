#pragma once
#include <CANTalon.h>
#include <iostream>

#include "Reference.h"

class Gearmech
{
private:
    CANTalon arm;
    CANTalon roller;
public:
    Gearmech();

    void SetArm(double speed);
    void SetRoller(double roller);
}
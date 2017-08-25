#pragma once
#include <CANTalon.h>
#include <iostream>

#include "Reference.h"

class Climber
{
private:
    CANTalon climber;
public:
    Climber();

    void climb(double speed);
}
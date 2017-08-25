#pragma once
#include "Drivetrain.h"
#include "Gearmech.h"
#include "Climber.h"

class subsystems
{
public:
    static Drivetrain drivetrain;
    static Gearmech gearmech;
    static Climber climber;
}
#include "Gearmech.h"

Gearmech::Gearmech()
    :
    arm(Reference::armid),
    roller(Reference::rollerid)
{
}

void Gearmech::setArm(double speed)
{
    arm.Set(speed);
}

void Gearmech::setRoller(double speed)
{
    roller.Set(speed);
}
#include "Climber.h"

Climber::Climber(Reference* ref)
    :
    motor(ref->motorid)
{
    r = ref;
}

void Climber::setSpeed(double power)
{
    motor.Set(power);
}
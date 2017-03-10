#include "Climber.h"

Climber::Climber()
    :
    motor(Reference::motorid)
{
}

void Climber::setSpeed(double power)
{
    motor.Set(power);
}
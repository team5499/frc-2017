#include "Climber.h"

Climber::Climber()
:
climber(Reference::climber_port)
{
    climber.SetInverted(true);
}
void Climber::climb(double speed)
{
    climber.Set(speed);
}
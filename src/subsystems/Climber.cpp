#include "Climber.h"

namespace team5499
{
    Climber::Climber()
    :
    climber_left(Reference::climber_left_port),
    climber_right(Reference::climber_right_port)
    {
        climber_left.SetInverted(true);
        climber_right.SetInverted(true);
    }
    void Climber::SetClimber(double speed)
    {
        climber_left.Set(speed);
        climber_right.Set(speed);
    }
}
#include "Climber.h"

namespace team5499
{
    void Climber::SetClimber(double speed)
    {
        hardware::climber_left.Set(speed);
        hardware::climber_right.Set(speed);
    }
}
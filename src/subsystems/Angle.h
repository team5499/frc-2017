#pragma once

#include <WPILib.h>
#include "../Reference.h"

namespace team5499
{
    class Angle
    {
    private:
        double angle;
        double last_left_distance;
        double last_right_distance;
    public:
        Angle();
        void handle(double leftValue, double rightValue);
        double getAngle();
        void reset();
        void resetLastDistances();
    };
}
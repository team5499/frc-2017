#pragma once
#include "../Hardware.h"

namespace team5499
{
    class Drivetrain
    {
        public:
            Drivetrain();

            static void driveLR(double left, double right)
            {
                hardware::drive_left1.Set(left);
                hardware::drive_left2.Set(left);
                hardware::drive_right1.Set(right);
                hardware::drive_right2.Set(right);
            }
    };
}
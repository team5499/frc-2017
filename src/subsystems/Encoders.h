#pragma once

#include <WPILib.h>
#include "../Reference.h"

namespace team5499
{
    class Encoders
    {
    private:
        Encoder left_encoder;
        Encoder right_encoder;
    public:
        Encoders();
        double getLeftDistance();
        double getRightDistance();
        void reset();
    };
}
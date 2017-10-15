#pragma once

#include <iostream>
#include "WPILib.h"
#include "CANTalon.h"
#include "../Reference.h"


namespace team5499 {
    class Climber {
    private:
        CANTalon climber1, climber2;
    public:
        Climber();
        void climb(double);
        void stop();
    };
}
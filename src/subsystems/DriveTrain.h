#include <iostream>
#include "WPIlib.h"
#include "CANTalon.h"
#include "../Reference.h"


namespace team5499 {
    class DriveTrain {
    private:
        CANTalon front_left, back_left, front_right, back_right;
    public:
        DriveTrain();
        void drive(double, double);
        void stop();
    };
}
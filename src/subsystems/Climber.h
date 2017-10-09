#include <iostream>
#include "WPILib.h"
#include "CANTalon.h"


namespace team5499 {
    class Climber {
    private:
        CANTalon climber1, climber2;
    public:
        Climber();
        void climb();
    };
}
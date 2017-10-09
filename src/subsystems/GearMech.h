#include <iostream>
#include "WPILib.h"
#include "CANTalon.h"

namespace team5499 {
    class GearMech {
    private:
        CANTalon roll, arm;
    public:
        GearMech();
        void armUp(double);
        void armDown(double);
        void intake();
        void outtake();
    };
}
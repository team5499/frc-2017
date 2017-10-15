#include <iostream>
#include "WPILib.h"
#include "CANTalon.h"
#include "../Reference.h"

namespace team5499 {
    class GearMech {
    private:
        CANTalon roll, arm;
    public:
        GearMech();
        void SetArm(double);
        void intake();
        void outtake();
        void stopRoll();
    };
}
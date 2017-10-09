#include "GearMech.h"

namespace team5499 {
    GearMech::GearMech()
    :
    roll(Reference::roller_port),
    arm(Reference::arm_port)
    {

    }

    void GearMech::SetArm(double a) {
        arm.Set(a);
    }

    void GearMech::intake() {
        roll.Set(Reference::roller_speed);
    }

    void GearMech::outtake() {
        roll.Set(-Reference::roller_speed);
    }
    
}
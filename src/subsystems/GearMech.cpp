#include "GearMech.h"

namespace team5499 {
    GearMech::GearMech()
    :
    roll(Reference::roller_port);
    arm(Reference::arm_port);

    void armDown() {
        arm.setPosition(0);
    }

    void armUp() {
        arm.setPosition(-Reference::PI / 4)
    }

    void intake() {
        roll.Set(Reference::roller_speed);
    }

    void outake() {
        roll.Set(-Reference::roller_speed);
    }
    
}
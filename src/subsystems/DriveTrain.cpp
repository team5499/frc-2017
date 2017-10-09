#include "DriveTrain.h"

namespace team5499 {
    DriveTrain::DriveTrain()
    :
    front_left(Reference::front_left_port),
    back_left(Reference::back_left_port),
    front_right(Reference::front_right_port),
    back_right(Reference::back_right_port)
    {
    front_right.SetInverted(true);
    back_right.SetInverted(true);
    }

    void DriveTrain::drive(double left, double right) {
        front_left.Set(left);
        back_left.Set(left);
        front_right.Set(right);
        back_right.Set(right);
    }
}
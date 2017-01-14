#include "Drivetrain.h"

Drivetrain::Drivetrain(Reference* ref, Hardware* hardware)
{
    r = ref;
    h = hardware;
    left1 = &(h->left1);
    left2 = &(h->left2);
    right1 = &(h->right1);
    right2 = &(h->right2);
}

void Drivetrain::driveLR(double left, double right) {
    // We aren't going to put anything in this
    // until we're sure we won't strip our gearboxes or fuck up our motors
}

void Drivetrain::shift(ShiftState state) {
    // I forget how solenoids work
}
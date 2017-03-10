#include "Drivetrain.h"

Drivetrain::Drivetrain()
    :
    left1(Reference::left1id),
    left2(Reference::left2id),
    right1(Reference::right1id),
    right2(Reference::right2id)
{
}

void Drivetrain::driveLR(double left, double right) {
    left1.Set(left);
    left2.Set(left);
    right1.Set(right);
    right2.Set(right);
}
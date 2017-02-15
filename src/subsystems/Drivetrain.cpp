#include "Drivetrain.h"

Drivetrain::Drivetrain(Reference* ref)
    :
    left1(ref->left1id),
    left2(ref->left2id),
    right1(ref->right1id),
    right2(ref->right2id),
{
    r = ref;
}

void Drivetrain::driveLR(double left, double right) {
    left1.Set(left);
    left2.Set(left);
    right1.Set(right);
    right2.Set(right);
}
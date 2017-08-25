#include "Drivetrain.h"

Drivetrain::Drivetrain()
:
drive_left1(Reference::drive_left1_addr),
drive_left2(Reference::drive_left2_addr),
drive_right1(Reference::drive_right1_addr),
drive_right2(Reference::drive_right2_addr)
{
    drive_left1.SetInverted(true);
    drive_left2.SetInverted(true);

    drive_left1.SetVoltageRampRate(10);
    drive_left2.SetVoltageRampRate(10);
    drive_right1.SetVoltageRampRate(10);
    drive_right2.SetVoltageRampRate(10);
}

void Drivetrain::DriveLR(double left, double right)
{
    drive_left1.Set(left);
    drive_left2.Set(left);

    drive_right1.Set(right);
    drive_right2.Set(right);
}
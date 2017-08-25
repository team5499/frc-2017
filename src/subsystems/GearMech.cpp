#include "Gearmech.h"

Gearmech::Gearmech()
:
arm(Reference::intake_arm_port),
roller(Reference::intake_roller_port)
{
    arm.SetInverted(false);
}
void Gearmech::SetArm(double speed)
{
    arm.Set(speed);
}
void Gearmech::SetRoller(double speed)
{
    roller.Set(speed);
}
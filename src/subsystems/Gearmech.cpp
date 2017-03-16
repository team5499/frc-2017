#include "Gearmech.h"

Gearmech::Gearmech()
    :
    arm(Reference::armid),
    roller(Reference::rollerid),
    intake_pot(Reference::potport),
    armController(Reference::kP, Reference::kI, Reference::kD, &intake_pot, &arm)
{
    
}

void Gearmech::setArm(double setpoint)
{
    point = setpoint;
    armController.SetSetpoint(point);
}

void Gearmech::setRoller(double speed)
{
    roller.Set(speed);
}

void Gearmech::enable()
{
    armController.Enable();
}

void Gearmech::disable()
{
    armController.Disable();
}
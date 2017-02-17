#include "Drivetrain.h"

Drivetrain::Drivetrain(Reference* ref)
        :
        left1(ref->left1id), left2(ref->left2id), right1(ref->right1id),
        right2(ref->right2id), lshift(ref->solenoidleftid),
        rshift(ref->solenoidrightid)
{
  r = ref;
}

void Drivetrain::driveLR(double left, double right)
{
  // We aren't going to put anything in this
  // until we're sure we won't strip our gearboxes or fuck up our motors
}

void Drivetrain::shift(ShiftState state)
{
  if(state == ShiftState::LOW)
  {
    lshift.Set(false);
    rshift.Set(false);
  }
  else
  {
    lshift.Set(true);
    rshift.Set(true);
  }
  currentShift = state;
}
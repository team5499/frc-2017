#include "Drivetrain.h"

namespace team5499
{
  Drivetrain::Drivetrain()
  :
  drive_left1(Reference::drive_left1_port),
  drive_left2(Reference::drive_left2_port),
  drive_right1(Reference::drive_right1_port),
  drive_right2(Reference::drive_right2_port)
  {
    drive_right1.SetInverted(true);
    drive_right2.SetInverted(true);
  }
  void Drivetrain::Drive(double left, double right) {
    drive_left1.Set(left);
    drive_left2.Set(left);
    drive_right1.Set(right);
    drive_right2.Set(right);
  }
}
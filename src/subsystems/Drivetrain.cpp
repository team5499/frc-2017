#include "Drivetrain.h"

namespace team5499
{
  Drivetrain::Drivetrain()
  :
  drive_left1(0),
  drive_left2(1),
  drive_right1(2),
  drive_right2(3)
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
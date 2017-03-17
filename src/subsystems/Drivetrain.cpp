#include "Drivetrain.h"

namespace team5499
{
  void Drivetrain::Drive(double left, double right) {
    hardware::drive_left1.Set(left);
    hardware::drive_left2.Set(left);
    hardware::drive_right1.Set(right);
    hardware::drive_right2.Set(right);
  }
}
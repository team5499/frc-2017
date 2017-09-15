#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

namespace team5499
{
  class Drivetrain
  {
  private:
    CANTalon drive_left1, drive_left2, drive_right1, drive_right2;
  public:
    Drivetrain();
    void Drive(double left, double right);
  };
}
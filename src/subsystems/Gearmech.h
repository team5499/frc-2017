#pragma once

#include "../Hardware.h"
#include "../util/PID.h"

namespace team5499
{
  class GearMech
  {
  private:
    double setpoint = 0.91;

  public:
    void SetSetpoint(double sp);
    void handle();
  };
}
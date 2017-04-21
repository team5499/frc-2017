#pragma once

#include "../Hardware.h"

namespace team5499
{
  class GearMech
  {
  private:
    double setpoint = 0.91;
    double initial_pv = 0;

  public:
    void SetInitialPV(double pv);
    void SetSetpoint(double sp);
    void handle();
    void SetArm(double speed);
    void SetRoller(double speed);
    bool seeGear();
  };
}
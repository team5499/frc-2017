#pragma once

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class IntakeMoveCommand : public GenericCommand
  {
  private:
    double setPoint;
  public:
    IntakeMoveCommand(double timeout, double set)
      :
      GenericCommand(timeout),
      setPoint(set)
    {
    }

    void Step() override
    {
      subsystems::gearmech.SetArm(setPoint);
    }
  };
}
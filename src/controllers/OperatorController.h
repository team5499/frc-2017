#pragma once

#include "GenericController.h"
#include "../subsystems/Gearmech.h"
#include "../subsystems/Climber.h"
#include "../subsystems/Drivetrain.h"

namespace team5499
{
  class OperatorController : public GenericController
  {
  public:
    void handle();
    void start();
  };
}
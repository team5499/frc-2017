#pragma once

#include "GenericController.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class OperatorController : public GenericController
  {
  private:
    Timer timer;
    int millis;
    bool flash;
  public:
    void Start() override;
    void Handle() override;
    void flashLEDs();
  };
}
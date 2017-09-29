#pragma once

#include "GenericController.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class OperatorController : public GenericController
  {
  public:
    void Start() override;
    void Handle() override;
  };
}
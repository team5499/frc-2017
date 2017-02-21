#pragma once

#include <WPILib.h>

#include <utility>

#include "GenericController.h"
#include "../Hardware.h"

class OperatorController : public GenericController
{
private:
  // Disable copy constructors
  OperatorController(const OperatorController&) = delete;
  OperatorController& operator=(const OperatorController&) = delete;

  Hardware& hardware;

public:
  OperatorController(Hardware& hardware);
  void handle() override;
};
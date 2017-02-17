#pragma once

#include <WPILib.h>

#include <utility>

#include "GenericController.h"
#include "../Hardware.h"
#include "../Reference.h"

class OperatorController : public GenericController
{
private:
  // Disable copy constructors
  OperatorController(const OperatorController&) = delete;
  OperatorController& operator=(const OperatorController&) = delete;

  Reference& reference;
  Hardware& hardware;
public:
  OperatorController(Reference& r, Hardware& h);
  void handle() override;
};
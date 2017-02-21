#pragma once

#include <WPILib.h>

#include <utility>

#include "GenericController.h"
#include "../Hardware.h"

class AutoController : public GenericController
{
private:
  // Disable copy constructors
  AutoController(const AutoController&) = delete;
  AutoController& operator=(const AutoController&) = delete;
public:
  AutoController();
  void handle() override;
};
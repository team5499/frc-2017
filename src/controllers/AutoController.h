#pragma once

#include <WPILib.h>

#include <utility>

#include "GenericController.h"
#include "../Hardware.h"
#include "../Reference.h"

class AutoController : public GenericController
{
private:
  // Disable copy constructors
  AutoController(const AutoController&) = delete;
  AutoController& operator=(const AutoController&) = delete;

  Reference& reference;
  Hardware& hardware;
public:
  AutoController(Reference& r, Hardware& h);
  void handle() override;
};
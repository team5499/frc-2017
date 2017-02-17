#pragma once

#include <WPILib.h>
#include "Reference.h"
#include "subsystems/Drivetrain.h"

class Hardware
{
private:
  // Disable copy constructors
  Hardware(const Hardware&) = delete;
  Hardware& operator=(const Hardware&) = delete;

public:
  Hardware() = default;
};
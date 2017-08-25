#pragma once
#include <WPILib.h>
#include <iostream>

#include "GenericController.h"
#include "Reference.h"
#include "subsystems.h"

class TeleopController : public GenericController
{
private:
    //input devices
    Joystick throttle;
    Joystick wheel;
    XboxController xbox;
public:
    TeleopController();
    void Handle() override;
};
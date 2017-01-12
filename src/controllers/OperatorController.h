#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"
#include "GenericController.h"
#include <iostream>

class OperatorController : public GenericController
{
    private:
        frc::Joystick wheel; //!< Reference to wheel for getting steering input.
        frc::Joystick throttle; //!< Reference to throttle for controlling speed.
        Reference* ref;
        Hardware* hardware;
    public:
        OperatorController(Reference* ref, Hardware* hardware);
        void handle();
        void start();
};
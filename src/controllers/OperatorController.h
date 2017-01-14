#pragma once
#include <WPILib.h>
#include "GenericController.h"
#include <iostream>

class OperatorController : public GenericController
{
    private:
        frc::Joystick wheel; //!< Reference to wheel for getting steering input.
        frc::Joystick throttle; //!< Reference to throttle for controlling speed.
        Reference* r;
        Hardware* h;
    public:
        OperatorController(Reference* ref, Hardware* hardware);
        void handle();
        void start();
};
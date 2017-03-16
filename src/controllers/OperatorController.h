#pragma once
#include <WPILib.h>
#include "GenericController.h"
#include <iostream>

class OperatorController : public GenericController
{
    private:
        frc::Joystick wheel; //!< Reference to wheel for getting steering input.
        frc::Joystick throttle; //!< Reference to throttle for controlling speed.
        frc::XboxController xbox; //!< Reference to xbox controller for controlling climb/gearmech.
    public:
        OperatorController();
        void handle();
        void start();
};
#pragma once

#include <iostream>
#include <WPILib.h>
#include "../Reference.h"
#include "ManualPID.h"

namespace team5499
{
    class HandlePID
    {
    public:
        HandlePID()
        :
        left_encoder(Reference::left_encoder_port1, Reference::left_encoder_port2),
        right_encoder(Reference::right_encoder_port1, Reference::right_encoder_port2),
        left_output(),
        right_output(),
        left_controller(Reference::kP, Reference::kI, Reference::kD, &left_encoder, &left_output, 0.01),
        right_controller(Reference::kP, Reference::kI, Reference::kD, &right_encoder, &right_output, 0.01),
        left_setpoint(0),
        right_setpoint(0)
        {
        }
        Encoder left_encoder;
        Encoder right_encoder;
        ManualPID left_output;
        ManualPID right_output;
        PIDController left_controller;
        PIDController right_controller;

        double left_setpoint;
        double right_setpoint;
    };
}
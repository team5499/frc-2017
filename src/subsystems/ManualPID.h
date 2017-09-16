#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

namespace team5499
{
    class ManualPID : public frc::PIDOutput
    {
    private:
        double lastOut = 0;
    public:
        double getOut() const {return lastOut;}
        void PIDWrite(double output) {lastOut = output;}
        ManualPID() {}
    };
}
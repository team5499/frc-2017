#pragma once

#include <WPILib.h>

namespace team5499
{
    class ManualPID : public PIDOutput
    {
    private:
        double lastOut = 0;
    public:
        double getOut() const {return lastOut;}
        void PIDWrite(double output) {lastOut = output;}
        ManualPID() {}
    };
}
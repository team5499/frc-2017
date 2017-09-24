#pragma once

#include <iostream>

namespace team5499
{
    class PID
    {
    private:
        double kP;
        double kI;
        double kD;
        double ov;
        double pv;
    public:
        PID();
        setInput();
    };
}
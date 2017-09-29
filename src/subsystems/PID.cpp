#include "PID.h"

namespace team5499
{
    PID::PID(double pVal, double iVal, double dVal, double output_cap)
    :
    kP(pVal),
    kI(iVal),
    kD(dVal),
    ov_cap(output_cap),
    ov(0),
    pv(0),
    sp(0),
    prev_pv(0),
    last_input_time(0),
    prev_error(0),
    prev_time(0),
    integral(0),
    derivative(0)
    {
    }
    void PID::setSetpoint(double set)
    {
        sp += set;
    }
    double PID::getSetpoint()
    {
        return sp;
    }
    void PID::setInput(double input)
    {
        prev_pv = pv;
        last_input_time = Timer::GetFPGATimestamp();
        pv = input;
    }
    void PID::calculate()
    {
        double error = sp - pv;
        double timeError = Timer::GetFPGATimestamp()-prev_time;
        integral += (error*timeError);
        prev_time = Timer::GetFPGATimestamp();
        derivative = (error-prev_error)/timeError;
        prev_error = error;
        ov = (kP*error) + (kI*integral) + (kD*derivative);

        if(ov > ov_cap)
            ov = ov_cap;
        if(ov < -ov_cap)
            ov = -ov_cap;
            

    }
    double PID::getOutput()
    {
        return ov;
    }
    double PID::getError()
    {
        return sp - pv;
    }
    double PID::getRate()
    {
        return (pv - prev_pv)/(Timer::GetFPGATimestamp() - last_input_time);
    }
    void PID::reset()
    {
        ov = 0;
        pv = 0;
        sp = 0;
        prev_pv = 0;
        last_input_time = 0;
        prev_error = 0;
        prev_time = 0;
        integral = 0;
        derivative = 0;
    }
}
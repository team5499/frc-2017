/*
* This class implements a manual PID controller
*/
#pragma once

#include <iostream>
#include <WPILib.h>

namespace team5499
{
    class PID
    {
    private:
        const double kP; // proportional constant
        const double kI; // integral constant
        const double kD; // derivative constant
        const double ov_cap;
        double ov; // output value
        double pv; // process value
        double sp; // set point
        double prev_pv;
        double last_input_time;
        double prev_error; // previous error for the PID loop
        double prev_time; // previous measured time for the PID loop
        double integral; // integral accumulation
        double derivative;
    public:
        PID(double pVal, double iVal, double dVal, double output_cap);
        void setSetpoint(double set); // set the setpoint of the PID loop
        double getSetpoint(); // get the setpoint
        void setInput(double input); // set the value coming from the sensor
        void calculate(); // calculate the PID output
        double getOutput(); // get the output of the loop
        double getError();
        double getRate();
        void reset();
    };
}
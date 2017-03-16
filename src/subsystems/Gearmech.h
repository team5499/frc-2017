#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "../Reference.h"

class Gearmech
{
    private:
        CANTalon arm;
        CANTalon roller;
        double point = 0.91;
        frc::AnalogInput intake_pot;
        frc::PIDController armController;

    public:

        Gearmech();
        void setArm(double setpoint);
        void setRoller(double speed);
        void enable();
        void disable();
};
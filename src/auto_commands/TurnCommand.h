#pragma once

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
    class TurnCommand : public GenericCommand
    {
    private:
        double m_setpoint;
    public:
        TurnCommand(double timeout, double setpoint)
        :
        GenericCommand(timeout),
        m_setpoint(setpoint)
        {
        }
        void start() override
        {
            GenericCommand::start();
            subsystems::anglepid.setSetpoint(m_setpoint);
        }
        void handle()
        {
            subsystems::anglepid.setInput(subsystems::angle.getAngle());

            subsystems::anglepid.calculate();

            subsystems::drivetrain.Drive(-subsystems::anglepid.getOutput(), subsystems::anglepid.getOutput());
        }
        bool isFinished() override
        {
            GenericCommand::isFinished();
            std::cout << subsystems::anglepid.getRate() << std::endl;
            if(subsystems::anglepid.getError() < 1 && subsystems::anglepid.getRate() < 0.2)
                return true;
            return false;
        }
        void reset() override
        {
        }
    };
}
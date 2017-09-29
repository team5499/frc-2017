#pragma once

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
    class DriveCommand : public GenericCommand
    {
    private:
        double m_setpoint;
    public:
        DriveCommand(double timeout, double setpoint)
        :
        GenericCommand(timeout),
        m_setpoint(setpoint)
        {
        }
        void start() override
        {
            GenericCommand::start();
            subsystems::leftpid.setSetpoint(m_setpoint);
            subsystems::rightpid.setSetpoint(m_setpoint);
            subsystems::anglepid.setSetpoint(0);
        }
        void handle()
        {
            subsystems::leftpid.setInput(subsystems::encoders.getLeftDistance());
            subsystems::rightpid.setInput(subsystems::encoders.getLeftDistance());
            subsystems::anglepid.setInput(subsystems::angle.getAngle());

            subsystems::leftpid.calculate();
            subsystems::rightpid.calculate();
            subsystems::anglepid.calculate();

            std::cout << subsystems::leftpid.getOutput() << ":" << subsystems::rightpid.getOutput() << std::endl;

            subsystems::drivetrain.Drive(-subsystems::leftpid.getOutput()-subsystems::anglepid.getOutput(), -subsystems::rightpid.getOutput()+subsystems::anglepid.getOutput());
        }
        bool isFinished() override
        {
            GenericCommand::isFinished();
            std::cout << subsystems::leftpid.getRate() << ":" << subsystems::rightpid.getRate() << ":" << subsystems::anglepid.getRate() << std::endl;
            if(subsystems::leftpid.getError() < 3 && subsystems::rightpid.getError() < 3 && subsystems::anglepid.getError() < 1 && subsystems::leftpid.getRate() < 3 && subsystems::rightpid.getRate() < 3 && subsystems::anglepid.getRate() < 0.2)
                return true;
            return false;
        }
        void reset() override
        {
        }
    };
}
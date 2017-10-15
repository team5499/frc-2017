#pragma once

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
    class DriveCommand : public GenericCommand
    {
    private:
        double m_setpoint;
        double m_starttime;
    public:
        DriveCommand(double timeout, double setpoint)
        :
        GenericCommand(timeout),
        m_setpoint(setpoint),
        m_starttime(0)
        {
        }
        void start() override
        {
            GenericCommand::start();
            subsystems::leftpid.setSetpoint(m_setpoint);
            subsystems::rightpid.setSetpoint(m_setpoint);
            subsystems::anglepid.setSetpoint(0);
            m_starttime = Timer::GetFPGATimestamp();
        }
        void handle()
        {
            subsystems::leftpid.setInput(subsystems::encoders.getLeftDistance());
            subsystems::rightpid.setInput(subsystems::encoders.getRightDistance());
            subsystems::anglepid.setInput(subsystems::angle.getAngle());

            subsystems::leftpid.calculate();
            subsystems::rightpid.calculate();
            subsystems::anglepid.calculate();

            double leftDrive = -subsystems::leftpid.getOutput();
            double rightDrive = -subsystems::rightpid.getOutput();

            if(leftDrive > 0.3)
                leftDrive = 0.3;
            if(leftDrive < -0.3)
                leftDrive = -0.3;

            if(rightDrive > 0.3)
                rightDrive = 0.3;
            if(rightDrive < -0.3)
                rightDrive = -0.3;



            //std::cout << subsystems::leftpid.getOutput() << ":" << subsystems::rightpid.getOutput() << ":" << subsystems::rightpid.getSetpoint() << std::endl;

            subsystems::drivetrain.Drive(leftDrive-subsystems::anglepid.getOutput(), rightDrive+subsystems::anglepid.getOutput());
            updateSmartDashboard();
        }
        bool isFinished() override
        {
            //std::cout << subsystems::leftpid.getRate() << ":" << subsystems::rightpid.getRate() << ":" << subsystems::anglepid.getRate() << std::endl;
            //if(subsystems::leftpid.getError() < 3 && subsystems::rightpid.getError() < 3 && subsystems::anglepid.getError() < 1 && subsystems::leftpid.getRate() < 3 && subsystems::rightpid.getRate() < 3 && subsystems::anglepid.getRate() < 0.2)
            //    return true;
            
            return GenericCommand::isFinished();
        }
        void updateSmartDashboard()
        {
            SmartDashboard::PutNumber("auto/curr_time", Timer::GetFPGATimestamp() - m_starttime);
            SmartDashboard::PutNumber("auto/left_error", subsystems::leftpid.getError());
            SmartDashboard::PutNumber("auto/right_error", subsystems::rightpid.getError());
            SmartDashboard::PutNumber("auto/angle_error", subsystems::anglepid.getError());
        }
        void reset() override
        {
        }
    };
}
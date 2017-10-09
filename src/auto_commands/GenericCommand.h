#pragma once

#include <WPILib.h>
#include "../subsystems/Subsystems.h"

namespace team5499
{
    class GenericCommand
    {
    private:
        double m_timeout;
        double m_start_time;
    public:
        GenericCommand() = delete;

        GenericCommand(double timeout)
        :
        m_timeout(timeout)
        {
        }

        virtual ~GenericCommand() {};
        virtual void handle() = 0;
        virtual void start()
        {
            m_start_time = Timer::GetFPGATimestamp();
        }
        virtual bool isFinished()
        {
            std::cout << Timer::GetFPGATimestamp() - m_start_time << std::endl;
            if(m_timeout < Timer::GetFPGATimestamp() - m_start_time)
            {
                std::cout << "timeout stop" << std::endl;
                return true;
            }
            return false;
        }
        virtual void reset() = 0;
    };
}
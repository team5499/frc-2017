#pragma once

#include "GenericCommand.h"

namespace team5499
{
    class DoNothingCommand : public GenericCommand
    {
    private:
    public:
        DoNothingCommand(double timeout)
        :
        GenericCommand(timeout)
        {
        }
        void start() override
        {
            GenericCommand::start();
        }
        void handle()
        {
        }
        bool isFinished() override
        {
            GenericCommand::isFinished();
        }
        void reset() override
        {
        }
    };
}
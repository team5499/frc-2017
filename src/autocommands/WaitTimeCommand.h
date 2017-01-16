#pragma once
#include <WPILib.h>
#include "GenericCommand.h"
#include <chrono>

class WaitTimeCommand : public GenericCommand
{
    private:
        int wait_time;
        std::chrono::time_point<std::chrono::system_clock> start;
    public:
        WaitTimeCommand(Reference* r, Hardware* h, int t);
        void init();
        void step();
        bool finished();
};
#pragma once
#include <WPILib.h>
#include "GenericCommand.h"

class NullCommand : public GenericCommand
{
    public:
        NullCommand(Reference* r, Hardware* h);
        void init();
        void step();
        bool finished();
};
#pragma once
#include <WPILib.h>
#include "GenericCommand.h"

class NullCommand : public GenericCommand
{
    public:
        NullCommand();
        void init();
        void step();
        bool finished();
};
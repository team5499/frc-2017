#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"

namespace team5499
{
    class GenericCommand
    {
        private:

        public:
            virtual ~GenericCommand() {};
            virtual void init() = 0;
            virtual void step() = 0;
            virtual bool finished() = 0;
    };
}
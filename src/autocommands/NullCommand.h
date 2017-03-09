#pragma once
#include "GenericCommand.h"

namespace team5499
{
    class NullCommand : public GenericCommand
    {
        private:

        public:
            NullCommand();

            void init() {};
            void step() {};
            bool finished() {return true;}
    };
}
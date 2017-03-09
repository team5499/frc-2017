#pragma once
#include "GenericCommand.h"

namespace team5499
{
    class DriveStraightCommand : public GenericCommand
    {
        private:
            int time;
            int distance;
        public:
            DriveStraightCommand(int dist);

            void init();
            void step();
            bool finished();
    };
}
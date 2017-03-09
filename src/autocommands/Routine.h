#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"
#include "GenericCommand.h"
#include "NullCommand.h"
#include "DriveStraightCommand.h"
#include <vector>

namespace team5499
{
    class Routine
    {
        private:
            int current;
            NullCommand cnull;
            std::vector<GenericCommand*> commands;
        public:
            Routine(std::vector<GenericCommand*> steps);

            GenericCommand* nextCommand();
            GenericCommand* currentCommand();

            bool stepFinished();
            bool routineFinished();
    };
}
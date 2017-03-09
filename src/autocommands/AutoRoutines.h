#pragma once
#include <vector>
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"
#include "Routine.h"

namespace team5499
{
    class AutoRoutines
    {
        private:
            std::vector<GenericCommand*> mainRoutineCommands;
        public:
            AutoRoutines()
                :
                mainRoutine(mainRoutineCommands)
            {
                mainRoutineCommands = 
                {
                };
            }
            static Routine mainRoutine;
    };
}
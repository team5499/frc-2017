#pragma once
#include "GenericCommand.h"
#include "NullCommand.h"
#include <vector>

class Routine
{
    private:
        int nsteps;
        int currStep = 0;
        std::vector<GenericCommand*> commands;

        NullCommand dnull;
    public:
        Routine();
        GenericCommand* nextStep();
        GenericCommand* currentCommand();
        bool stepFinished();
        bool routineFinished();
};
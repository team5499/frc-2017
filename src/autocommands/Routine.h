#pragma once
#include "GenericCommand.h"
#include "NullCommand.h"
#include <vector>

class Routine
{
    private:
        Reference* r;
        Hardware* h;

        int nsteps;
        int currStep = 0;
        std::vector<GenericCommand*> commands;

        NullCommand dnull;
    public:
        Routine(Reference* ref, Hardware* h);
        GenericCommand* nextStep();
        GenericCommand* currentCommand();
        bool stepFinished();
        bool routineFinished();
};
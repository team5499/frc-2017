#pragma once

#include "GenericAutoCommand.h"
#include "DoNothingCommand.h"
#include "DriveDistanceCommand.h"
#include "TurnCommand.h"
#include "MoveGearmechCommand.h"
#include <vector>

namespace team5499
{
    class LeftRoutine
    {
    private:
        int nSteps = 0;
        int currStep;
        std::vector<GenericAutoCommand*> commands;

        DoNothingCommand dncmd;
    public:
        LeftRoutine();
        GenericAutoCommand* nextStep();
        GenericAutoCommand* currentCommand();
        bool stepFinished();
        bool routineFinished();
    };
}
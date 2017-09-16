#include "LeftRoutine.h"

namespace team5499
{
    LeftRoutine::LeftRoutine()
    :
    currStep(0),
    dncmd()
    {
        commands.push_back(new DriveDistanceCommand(20));
        commands.push_back(new TurnCommand(60));
        commands.push_back(new DriveDistanceCommand(20));
        commands.push_back(new MoveGearmechCommand(0.5));
        commands.push_back(new DriveDistanceCommand(-20));
        commands.push_back(new MoveGearmechCommand(-0.75));
        commands.push_back(new MoveGearmechCommand(0));

        nSteps = commands.size();
    }
    GenericAutoCommand* LeftRoutine::nextStep()
    {
        if (nSteps > currStep+1) { // If we aren't on the last step
            currStep++;
            return commands.at(currStep);
        }
        else {
            return &dncmd;
        }
    }
    GenericAutoCommand* LeftRoutine::currentCommand()
    {
        return commands.at(currStep);
    }
    bool LeftRoutine::stepFinished()
    {
        return commands.at(currStep)->isFinished();
    }
    bool LeftRoutine::routineFinished()
    {
        return (currStep == nSteps);
    }

}
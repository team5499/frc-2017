#include "RightRoutine.h"

namespace team5499
{
    RightRoutine::RightRoutine()
    :
    currStep(0),
    dncmd()
    {
        commands.push_back(new DriveDistanceCommand(20));
        commands.push_back(new TurnCommand(-60));
        commands.push_back(new DriveDistanceCommand(20));
        commands.push_back(new MoveGearmechCommand(0.5));
        commands.push_back(new DriveDistanceCommand(-20));
        commands.push_back(new MoveGearmechCommand(-0.75));
        commands.push_back(new MoveGearmechCommand(0));

        nSteps = commands.size();
    }
    GenericAutoCommand* RightRoutine::nextStep()
    {
        if (nSteps > currStep+1) { // If we aren't on the last step
            currStep++;
            return commands.at(currStep);
        }
        else {
            return &dncmd;
        }
    }
    GenericAutoCommand* RightRoutine::currentCommand()
    {
        return commands.at(currStep);
    }
    bool RightRoutine::stepFinished()
    {
        return commands.at(currStep)->isFinished();
    }
    bool RightRoutine::routineFinished()
    {
        return (currStep == nSteps);
    }

}
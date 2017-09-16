#include "CenterRoutine.h"

namespace team5499
{
    CenterRoutine::CenterRoutine()
    :
    currStep(0),
    dncmd()
    {
        commands.push_back(new DriveDistanceCommand(20));
        commands.push_back(new MoveGearmechCommand(0.5));
        commands.push_back(new DriveDistanceCommand(-20));
        commands.push_back(new MoveGearmechCommand(-0.75));
        commands.push_back(new MoveGearmechCommand(0));

        nSteps = commands.size();
    }
    GenericAutoCommand* CenterRoutine::nextStep()
    {
        if (nSteps > currStep+1) { // If we aren't on the last step
            currStep++;
            return commands.at(currStep);
        }
        else {
            return &dncmd;
        }
    }
    GenericAutoCommand* CenterRoutine::currentCommand()
    {
        return commands.at(currStep);
    }
    bool CenterRoutine::stepFinished()
    {
        return commands.at(currStep)->isFinished();
    }
    bool CenterRoutine::routineFinished()
    {
        return (currStep == nSteps);
    }

}
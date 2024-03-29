#include "Routine.h"

Routine::Routine()
    :
    dnull()
{
    // Initialization of routine
    commands.push_back(new NullCommand());

    nsteps = commands.size();
}

GenericCommand* Routine::nextStep()
{   
    if (nsteps>currStep+1) { // If we aren't on the last step
        currStep++;
        return commands.at(currStep);
    }
    else {
        return &dnull;
    }
}

GenericCommand* Routine::currentCommand()
{
    return commands.at(currStep);
}

bool Routine::stepFinished()
{
    return commands.at(currStep)->finished();
}

bool Routine::routineFinished()
{
    return (currStep==nsteps);
}
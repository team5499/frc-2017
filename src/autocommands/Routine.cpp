#include "Routine.h"

namespace team5499
{
    Routine::Routine(std::vector<GenericCommand*> steps)
        :
        commands(steps),
        cnull()
    {
        current = 0;
    }

    GenericCommand* Routine::currentCommand()
    {
        return commands.at(current);
    }

    GenericCommand* Routine::nextCommand()
    {
        if (commands.size()>current+1) { // If we aren't on the last step
            current++;
            return commands.at(current);
        }
        
        return &cnull;
    }

    bool Routine::stepFinished()
    {
        return commands.at(current)->finished();
    }

    bool Routine::routineFinished()
    {
        return (current > commands.size()-1);
    }
}
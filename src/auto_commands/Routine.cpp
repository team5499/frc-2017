#include "Routine.h"

namespace team5499
{
    Routine::Routine()
    :
    step_number(0)
    {
    }
    void Routine::start()
    {
        current_command->start();
    }
    void Routine::handle()
    {
        if(current_command->isFinished())
        {
            if(!advanceRoutine())
                return;
        }
        else
            current_command->handle();
    }
    bool Routine::advanceRoutine()
    {
        if(!(step_number + 1 < commands.size()))
            return false;
        step_number++;
        current_command = commands.at(step_number);
        current_command->start();
        return true;
    }

    void Routine::reset()
    {
        step_number = 0;
        subsystems::leftpid.reset();
        subsystems::rightpid.reset();
        subsystems::anglepid.reset();
        for(int i = 0;i<commands.size();i++)
        {
            commands.at(i)->reset();
        }
        current_command = commands.at(0);
    }
}
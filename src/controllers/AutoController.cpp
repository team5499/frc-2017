#include "AutoController.h"

namespace team5499
{
    AutoController::AutoController(Routine r)
        :
        routine(r),
        currentCommand(r.currentCommand())
    {
    }

    void AutoController::handle()
    {
        if(routine.routineFinished()) {return;}

        currentCommand->step();
        if(routine.stepFinished())
        {
            currentCommand = routine.nextCommand();
            currentCommand->init();
        }
    }

    void AutoController::start()
    {
        std::cout << "Starting autonomous controller!" << std::endl;
    }
}
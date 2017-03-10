#include "AutoController.h"

AutoController::AutoController()
    :
    autoRoutine()
{
    currCommand = autoRoutine.currentCommand();
    std::cout << "Initialized Auto Controller." << std::endl;
    
}

void AutoController::handle()
{
    if (finished) {return;}
    finished = autoRoutine.routineFinished();

    currCommand->step();
    if (autoRoutine.stepFinished()) {
        currCommand = autoRoutine.nextStep();
        currCommand->init();
    }

}

void AutoController::start()
{
    std::cout << "Starting Auto Control." << std::endl;
}
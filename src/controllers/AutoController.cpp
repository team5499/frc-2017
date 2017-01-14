#include "AutoController.h"

AutoController::AutoController(Reference* ref, Hardware* hardware)
{
    r = ref;
    h = hardware;
    std::cout << "Initialized Auto Controller." << std::endl;
    
}

void AutoController::handle()
{
}

void AutoController::start()
{
    std::cout << "Starting Auto Control." << std::endl;
}
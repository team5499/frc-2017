#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController(Reference* ref, Hardware* hardware)
    :
    throttle(ref->throttle),
    wheel(ref->wheel)
{
    r = ref;
    h = hardware;
    std::cout << "Initialized Operator Controller." << std::endl;
    
}

void OperatorController::handle()
{
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}
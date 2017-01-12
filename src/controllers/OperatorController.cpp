#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController(Reference* r, Hardware* h)
    :
    throttle(ref->throttle),
    wheel(r->wheel)
{
    ref = r;
    hardware = h;
    std::cout << "Initialized Operator Controller." << std::endl;
    
}

void OperatorController::handle()
{
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}
#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController(Reference* ref, Hardware* hardware)
    :
    throttle(ref->throttle),
    wheel(ref->wheel),
    wheeldead(ref->wheeldeadzone),
    throttledead(ref->throttledeadzone)
{
    r = ref;
    h = hardware;
    std::cout << "Initialized Operator Controller." << std::endl;
    
}

void OperatorController::handle()
{
    double throttle_value = throttle.GetRawAxis(1);
    double wheel_value = wheel.GetRawAxis(0);
    if(std::fabs(throttle_value)<throttledead)
    {
        throttle_value = 0;
    }
    if(std::fabs(wheel_value)<wheeldead)
    {
        wheel_value = 0;
    }
    h->drivetrain.driveLR(throttle_value + wheel_value,
                          throttle_value - wheel_value);

    if (throttle.GetRawButton(r->climbbutton))
    {
        h->climber.setSpeed(1);
    }
    else
    {
        h->climber.setSpeed(0);
    }
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}
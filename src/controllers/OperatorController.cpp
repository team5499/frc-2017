#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController()
    :
    throttle(Reference::throttle),
    wheel(Reference::wheel),
    wheeldead(Reference::wheeldeadzone),
    throttledead(Reference::throttledeadzone)
{
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
    Hardware::drivetrain.driveLR(throttle_value + wheel_value,
                          throttle_value - wheel_value);

    if (throttle.GetRawButton(Reference::climbbutton))
    {
        Hardware::climber.setSpeed(1);
    }
    else
    {
        Hardware::climber.setSpeed(0);
    }
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}
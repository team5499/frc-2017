#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController()
    :
    throttle(Reference::throttle),
    wheel(Reference::wheel),
    xbox(Reference::xbox),
    wheeldead(Reference::wheeldeadzone),
    throttledead(Reference::throttledeadzone)
{
    std::cout << "Initialized Operator Controller." << std::endl;
    
}

void OperatorController::handle()
{
    double throttle_value = throttle.GetRawAxis(1);
    double wheel_value = wheel.GetRawAxis(0);
    double arm_value = xbox.GetRawAxis(1) * 0.25;
    double roller_value = (xbox.GetRawButton(3) * 0.25) + (xbox.GetRawAxis(2) * 0.1);
    int climb = xbox.GetRawButton(2);

    throttle_value = (std::fabs(throttle_value)<throttledead) ? 0 : throttle_value;
    wheel_value = (std::fabs(wheel_value)<wheeldead) ? 0 : wheel_value;

    Hardware::drivetrain.driveLR(throttle_value + wheel_value,
                          throttle_value - wheel_value);

    Hardware::climber.setSpeed(climb);

    Hardware::gearmech.setArm(arm_value);
    Hardware::gearmech.setRoller(roller_value);
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}
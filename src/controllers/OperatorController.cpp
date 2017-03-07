#include "OperatorController.h"

OperatorController::OperatorController()
{

}

void OperatorController::handle()
{
    Gearmech::setArm(hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand));
    if(hardware::xbox.GetAButton())
    {
        Gearmech::setRoller(1);
    }
    else if(hardware::xbox.GetBButton())
    {
        Gearmech::setRoller(-1);
    }
    else
    {
        Gearmech::setRoller(0);
    }

    if(hardware::xbox.GetXButton())
    {
        Climber::climb();
    }
    else{
        Climber::stop();
    }

    hardware::drive_left1.Set(hardware::throttle.GetRawAxis(1) - hardware::wheel.GetRawAxis(0));
    hardware::drive_left2.Set(hardware::throttle.GetRawAxis(1) - hardware::wheel.GetRawAxis(0));
    hardware::drive_right1.Set(hardware::throttle.GetRawAxis(1) + hardware::wheel.GetRawAxis(0));
    hardware::drive_right2.Set(hardware::throttle.GetRawAxis(1) + hardware::wheel.GetRawAxis(0));

    std::cout << hardware::wheel.GetRawAxis(0) << std::endl;
}

void OperatorController::start()
{

}
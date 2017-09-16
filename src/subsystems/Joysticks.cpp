#include "Joysticks.h"

namespace team5499
{
    Joysticks::Joysticks()
    :
    prev(false),
    config(2),
    xbox(Reference::xbox_port),
    driver(Reference::driver_port),
    throttle(Reference::throttle_port),
    wheel(Reference::wheel_port)
    {
    }
    void Joysticks::handleConfig()
    {
        if(xbox.GetBackButton()&&!prev)
        {
            prev = true;
            config = (config + 1) % 3;
            switch(config)
            {
                case 0:
                    std::cout << "Wheel" << std::endl;
                    break;
                case 1:
                    std::cout << "Tank" << std::endl;
                    break;
                case 2:
                    std::cout << "GTA 5" << std::endl;
                    break;
            }
        }
        else if(!xbox.GetBackButton()&&prev)
        {
            prev = false;
        }
        else
        {
        }
    }
    double Joysticks::getLeftValue()
    {
        double value = 0;
        double th = 0;
        double wh = 0;
                value = driver.GetY(Joystick::JoystickHand::kLeftHand);
            if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                value*=0.25;
            else if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                value*=0.6;
        return value;
    }
    double Joysticks::getRightValue()
    {
        double value = 0;
        double th = 0;
        double wh = 0;
                value = driver.GetY(Joystick::JoystickHand::kRightHand);
                if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                value*=0.25;
            else if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                value*=0.6;
        return value;
    }
    double Joysticks::getClimberValue()
    {
        return xbox.GetAButton();
    }
    double Joysticks::getRollerValue()
    {
        bool intake = xbox.GetBumper(Joystick::JoystickHand::kRightHand);
        bool outtake = xbox.GetBumper(Joystick::JoystickHand::kLeftHand);
        bool intake_slow = (xbox.GetTriggerAxis(Joystick::JoystickHand::kRightHand) > 0.5);
        if(intake)
            return 1;
        else if(outtake)
            return 1;
        else if(intake_slow)
            return 0.1;
        else
            return 0;
    }
    double Joysticks::getArmValue()
    {
        return 0.5*xbox.GetY(Joystick::JoystickHand::kLeftHand);
    }
}
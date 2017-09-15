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
        switch(config)
        {
            case 0:
                th = -throttle.GetRawAxis(1);
                if(throttle.GetRawButton(1))
                {
                    th *= 0.2;
                }
                wh = wheel.GetRawAxis(0);
                if(!wheel.GetRawButton(8))
                {
                    if(th > 0)
                        wh *= 0.4;
                    else
                        wh *= 0.25;
                }
                value = th - wh;
                break;
            case 1:
                value = driver.GetY(Joystick::JoystickHand::kLeftHand);
                break;
            case 2:
                th = driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) - driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
                wh = driver.GetX(Joystick::JoystickHand::kLeftHand);
                value = th - wh;
                break;
        }
        return 0;
    }
    double Joysticks::getRightValue()
    {
        double value = 0;
        double th = 0;
        double wh = 0;
        switch(config)
        {
            case 0:
                th = -throttle.GetRawAxis(1);
                if(throttle.GetRawButton(1))
                {
                    th *= 0.2;
                }
                wh = wheel.GetRawAxis(0);
                if(!wheel.GetRawButton(8))
                {
                    if(th > 0)
                        wh *= 0.4;
                    else
                        wh *= 0.25;
                }
                value = th + wh;
                break;
            case 1:
                value = driver.GetY(Joystick::JoystickHand::kRightHand);
                break;
            case 2:
                th = driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) - driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
                wh = driver.GetX(Joystick::JoystickHand::kLeftHand);
                value = th + wh;
                break;
        }
        return 0;
    }
    double Joysticks::getClimberValue()
    {
        return xbox.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) - xbox.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
    }
    double Joysticks::getRollerValue()
    {
        bool intake = xbox.GetBButton();
        bool outtake = xbox.GetXButton();
        bool intake_slow = xbox.GetYButton();
        if(intake)
            return 1;
        else if(outtake)
            return -0.65;
        else if(intake_slow)
            return 0.1;
        else
            return 0;
    }
    double Joysticks::getArmValue()
    {
        return xbox.GetY(Joystick::JoystickHand::kLeftHand);
    }
}
#include "Joysticks.h"

namespace team5499
{
    Joysticks::Joysticks()
    :
    prev(false),
    config(1),
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
                if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                    value*=0.25;
                else if(driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand) > 0.5)
                    value*=0.6;
                break;
            case 2:
                th = 0.75*(- driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) + driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand));
                wh = (0.45*driver.GetX(Joystick::JoystickHand::kLeftHand))+(0.3*driver.GetX(Joystick::JoystickHand::kRightHand));
                if(wh<0.1 && wh>-0.1)
                    wh = 0;
                value = th - wh;
                if(driver.GetBumper(Joystick::JoystickHand::kLeftHand))
                    value*=0.5;
                //std::cout << "drive:" << value << std::endl;
                break;
        }
        return value;
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
                if(driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) > 0.5)
                    value*=0.25;
                else if(driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand) > 0.5)
                    value*=0.6;
                break;
            case 2:
                th = - driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand) + driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
                wh = driver.GetX(Joystick::JoystickHand::kLeftHand);
                value = th + wh;
                if(driver.GetBumper(Joystick::JoystickHand::kLeftHand))
                    value*=0.5;
                break;
        }
        return value;
    }
    double Joysticks::getClimberValue()
    {
        bool climb_forward = xbox.GetAButton();
        bool climb_reverse = xbox.GetBButton();
        bool climb_slow = xbox.GetXButton();
        bool climb_slow_reverse = xbox.GetYButton();

        if(climb_forward)
            return 1;
        else if(climb_reverse)
            return -1;
        else if(climb_slow)
            return 0.2;
        else if(climb_slow_reverse)
            return -0.2;
        else
            return 0;
    }
    double Joysticks::getRollerValue()
    {
        bool intake = xbox.GetBumper(Joystick::JoystickHand::kRightHand);
        bool outtake = xbox.GetBumper(Joystick::JoystickHand::kLeftHand);
        bool intake_slow = (xbox.GetTriggerAxis(Joystick::JoystickHand::kRightHand) > 0.5);
        if(intake)
            return 1;
        else if(outtake)
            return -1;
        else if(intake_slow)
            return 0.15;
        else
            return 0;
    }
    double Joysticks::getArmValue()
    {
        return 0.45*xbox.GetY(Joystick::JoystickHand::kLeftHand);
    }
}
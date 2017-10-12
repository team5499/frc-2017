#include "JoySticks.h"

namespace team5499 {
   JoySticks::JoySticks()
    :
    driver(Reference::driver_port),
    coDriver(Reference::xbox_port)
    {

    }

    double JoySticks::getLeftStick() {
        float a = 0;
        a = driver.GetY(Joystick::JoystickHand::kLeftHand) * 0.6;
        return a;
    }

    double JoySticks::getRightStick() {
        float a = 0;
        a = driver.GetX(Joystick::JoystickHand::kRightHand) * 0.5;
        return a;
    }

    bool JoySticks::getClimb() {
        return driver.GetAButton();
    }

    double JoySticks::getArm() {
        float a = coDriver.GetY(Joystick::JoystickHand::kRightHand) * 0.5;
        return a;
    }

    int JoySticks::getIntake() {
        // 0 = in, 1 = out, -1 = error
        if(coDriver.GetBumper(Joystick::JoystickHand::kLeftHand)) {
            return 0;
        }
        else if(coDriver.GetBumper(Joystick::JoystickHand::kRightHand)) {
            return 1;
        }
        else {return -1;}
        
    }




}
#include "JoySticks.h"

namespace team5499 {
    JoySticks():
    :
    driver(Reference::driver_port),
    coDriver(Reference::xbox_port)

    float JoySticks::getRightStick() {
        float a = 0;
        a = driver.GetX(Joysticks::JoystickHand::Left);
        return a;
    }

    float JoySticks::getLeftStick() {
        float a = 0;
        a = driver.GetY(Joysticks::JoystickHand::Right);
        return a;
    }

    bool JoySticks::getClimber() {
        return driver.GetAButton();
    }

    float JoySticks::getArm() {
        float a = coDriver.GetY(Joysticks::JoystickHand::Left);
        return a;
    }

    int JoySticks::getIntake() {
        // 0 = in, 1 = out, -1 = error
        if(coDriver.GetBumper(Joysticks::JoystickHand::Left)) {
            return 0;
        }
        else if(coDriver.getBumper(Joysticks::JoystickHand::Right)) {
            return 1;
        }
        else {return -1;}
        
    }




}
#include "OperatorController.h"

namespace team5499
{
  void OperatorController::handle()
  {
//  Gearmech::setArm(hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand));
//  if(hardware::xbox.GetAButton())
//  {
//    Gearmech::setRoller(1);
//  }
//  else if(hardware::xbox.GetBButton())
//  {
//    Gearmech::setRoller(-1);
//  }
//  else
//  {
//    Gearmech::setRoller(0);
//  }
//
//  if(hardware::xbox.GetXButton())
//  {
//    Climber::climb();
//  }
//  else
//  {
//    Climber::stop();
//  }

    double throttle = hardware::throttle.GetRawAxis(1);
    double wheel = hardware::wheel.GetRawAxis(0);
    if(hardware::wheel.GetRawButton(8))
    {
      if(throttle > 0)
        wheel *= 0.4;
      else
        wheel *= 0.25;
    }

    hardware::drive_left1.Set(throttle - wheel);
    hardware::drive_left2.Set(throttle - wheel);
    hardware::drive_right1.Set(throttle + wheel);
    hardware::drive_right2.Set(throttle + wheel);
    std::cout << "Left: " << (throttle - wheel) << std::endl;
    std::cout << "Right: " << (throttle + wheel) << std::endl;
  }

  void OperatorController::start()
  {

  }
}
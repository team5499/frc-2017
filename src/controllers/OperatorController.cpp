#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::Step()
  {
    
    //Drivetrain
    double throttle = hardware::driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand)-hardware::driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
    double wheel = 0.75*hardware::driver.GetX(Joystick::JoystickHand::kRightHand);
    std::cout << wheel << std::endl;
    if(wheel>-0.075&&wheel<0.075)
      wheel = 0;
    //double right = -hardware::driver.GetY(Joystick::JoystickHand::kLeftHand);
    //double left = -hardware::driver.GetY(Joystick::JoystickHand::kRightHand);
    subsystems::drivetrain.Drive(throttle - wheel, throttle + wheel);

  }
}
#include "OperatorController.h"

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
    subsystems::drivetrain.Drive(throttle - wheel, throttle + wheel);
    //Gearmech
    double arm_speed = hardware::driver.GetY(Joystick::JoystickHand::kLeftHand);
    bool roller_forward = hardware::driver.GetBButton();
    bool roller_reverse = hardware::driver.GetYButton();
    bool roller_slow = hardware::driver.GetXButton();
    subsystems::gearmech.SetArm(arm_speed*0.35);
    if(roller_forward)
      subsystems::gearmech.SetRoller(0.8);
    else if(roller_reverse)
      subsystems::gearmech.SetRoller(-0.5);
    else if(roller_slow)
      subsystems::gearmech.SetRoller(0.1);
    else
      subsystems::gearmech.SetRoller(0);
    //Climber
    bool climb_forward = hardware::driver.GetAButton();
    if(climb_forward)
      subsystems::climber.SetClimber(1);
    else
      subsystems::climber.SetClimber(0);

  }
}
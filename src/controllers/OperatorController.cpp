#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::Step()
  {
    
    //Drivetrain
    double throttle = -hardware::driver.GetTriggerAxis(Joystick::JoystickHand::kLeftHand)+hardware::driver.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
    double wheel = (0.3*hardware::driver.GetX(Joystick::JoystickHand::kLeftHand)+hardware::driver.GetX(Joystick::JoystickHand::kRightHand))+0.09;
    std::cout << wheel << std::endl;
    if(wheel>-0.075&&wheel<0.075)
      wheel = 0;
    //double right = -hardware::driver.GetY(Joystick::JoystickHand::kLeftHand);
    //double left = -hardware::driver.GetY(Joystick::JoystickHand::kRightHand);
    subsystems::drivetrain.Drive(throttle - wheel, throttle + wheel);

    //Climber
    bool climb = hardware::codriver.GetRawButton(4);
    bool climb_slow = hardware::codriver.GetRawButton(6);
    if(climb)
      subsystems::climber.climb(1);
    else if(climb_slow)
      subsystems::climber.climb(0.2);
    else
      subsystems::climber.climb(0);

    bool climb_reverse = hardware::codriver.GetRawButton(5);
    if(climb_reverse)
      subsystems::climber.climb(-1);

    //LEDS
    if(subsystems::gearmech.seeGear())
    {
      subsystems::leds.setRed(true);
      subsystems::leds.setGreen(true);
      subsystems::leds.setBlue(true);
    }
    else
    {
      subsystems::leds.disable();
    }

    //Gearmech
    double intake = hardware::codriver.GetRawAxis(1);
    subsystems::gearmech.SetArm(-intake * .70);

    bool roller_intake = hardware::codriver.GetRawButton(1);
    bool roller_intake_slow = hardware::codriver.GetRawButton(2);
    bool roller_outtake = hardware::codriver.GetRawButton(3);

    if(roller_intake)
      subsystems::gearmech.SetRoller(0.6);
    else if(roller_intake_slow > 0.5)
      subsystems::gearmech.SetRoller(.1);
    else if(roller_outtake)
      subsystems::gearmech.SetRoller(-0.6);
    else
      subsystems::gearmech.SetRoller(0);
  }
}
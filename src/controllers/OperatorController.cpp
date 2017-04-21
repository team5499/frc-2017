#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::Step()
  {
    //Drivetrain
    double throttle = -hardware::throttle.GetRawAxis(1);
    if(hardware::throttle.GetRawButton(1))
    {
      throttle *= 0.2;
    }
    double wheel = hardware::wheel.GetRawAxis(0);
    if(!hardware::wheel.GetRawButton(8))
    {
      if(throttle > 0)
        wheel *= 0.4;
      else
        wheel *= 0.25;
    }
    subsystems::drivetrain.Drive(throttle - wheel, throttle + wheel);

    //Climber
    bool climb = hardware::xbox.GetRawButton(3);
    bool climb_slow = hardware::xbox.GetRawButton(4);
    if(climb)
      subsystems::climber.climb(1);
    else if(climb_slow)
      subsystems::climber.climb(0.2);
    else
      subsystems::climber.climb(0);

    bool climb_reverse = hardware::xbox.GetBButton();
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
    double intake = hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand);
    subsystems::gearmech.SetArm(-intake * .40);

    bool roller_intake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kRightHand);
    bool roller_intake_slow = hardware::xbox.GetTriggerAxis(
      Joystick::JoystickHand::kRightHand);
    bool roller_outtake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kLeftHand);

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
#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::Step()
  {
    double throttle = -hardware::throttle.GetRawAxis(1);
    double wheel = hardware::wheel.GetRawAxis(0);
    if(!hardware::wheel.GetRawButton(8))
    {
      if(throttle > 0)
        wheel *= 0.4;
      else
        wheel *= 0.25;
    }
    subsystems::drivetrain.Drive(throttle - wheel, throttle + wheel);

    bool roller_intake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kRightHand);
    bool roller_intake_slow = hardware::xbox.GetTriggerAxis(
      Joystick::JoystickHand::kRightHand);
    bool roller_outtake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kLeftHand);
    if(roller_intake)
      hardware::intake_roller.Set(0.6);
    else if(roller_intake_slow > 0.5)
      hardware::intake_roller.Set(0.1);
    else if(roller_outtake)
      hardware::intake_roller.Set(-0.6);
    else
      hardware::intake_roller.Set(0);

    bool climb = hardware::xbox.GetRawButton(3);
    if(climb)
      hardware::climber.Set(1);
    else
      hardware::climber.Set(0);

    double intake = hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand);
    hardware::intake_arm.Set(-intake * .25);
  }
}
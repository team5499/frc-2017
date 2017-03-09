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
    double intake = hardware::xbox.GetRawAxis(5);
    bool roller_intake = hardware::xbox.GetRawButton(2);
    bool roller_outtake = hardware::xbox.GetRawButton(1);
    bool climb = hardware::xbox.GetRawButton(3);
    if(hardware::wheel.GetRawButton(8))
    {
      if(throttle > 0)
        wheel *= 0.4;
      else
        wheel *= 0.25;
    }

    if(roller_intake)
      hardware::intake_roller.Set(1);
    else if(roller_outtake)
      hardware::intake_roller.Set(-1);
    else
      hardware::intake_roller.Set(0);

    if(climb)
      hardware::climber.Set(1);
    else
      hardware::climber.Set(0);

    hardware::intake_arm.Set(intake*.25);

    Drivetrain::driveLR(throttle - wheel, throttle + wheel);
  }

  void OperatorController::start()
  {

  }
}
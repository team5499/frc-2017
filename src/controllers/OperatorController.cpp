#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::handle()
  {
//  GearMech::setArm(hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand));
//  if(hardware::xbox.GetAButton())
//  {
//    GearMech::setRoller(1);
//  }
//  else if(hardware::xbox.GetBButton())
//  {
//    GearMech::setRoller(-1);
//  }
//  else
//  {
//    GearMech::setRoller(0);
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
    if(!hardware::wheel.GetRawButton(8))
    {
      if(throttle > 0)
        wheel *= 0.4;
      else
        wheel *= 0.25;
    }
    Drivetrain::driveLR(throttle + wheel, throttle - wheel);

    bool roller_intake = hardware::xbox.GetBumper(Joystick::JoystickHand::kRightHand);
    bool roller_intake_slow = hardware::xbox.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
    bool roller_outtake = hardware::xbox.GetBumper(Joystick::JoystickHand::kLeftHand);
    if(roller_intake)
      hardware::intake_roller.Set(0.6);
    else if(roller_intake_slow > 0.5)
      hardware::intake_roller.Set(0.1);
    else if(roller_outtake)
      hardware::intake_roller.Set(-0.6);
    else
      hardware::intake_roller.Set(0);

<<<<<<< HEAD
    bool climb = hardware::xbox.GetRawButton(3);
    if(climb)
      hardware::climber.Set(1);
    else
      hardware::climber.Set(0);

    if(hardware::xbox.GetRawButton(1))
    {
      subsystems::gearmech.SetSetpoint(0.91);
    }
    else if(hardware::xbox.GetRawButton(2))
    {
      subsystems::gearmech.SetSetpoint(2.53);
    }
    subsystems::gearmech.handle();
=======
    //LEDS
    hardware::leds.setRed(255);
    hardware::leds.setGreen(255);
    hardware::leds.setBlue(255);

//    bool climb = hardware::xbox.GetRawButton(3);
//    if(climb)
//      hardware::climber.Set(1);
//    else
//      hardware::climber.Set(0);
>>>>>>> cb3ae357397eaef343e9c4a2603d88770f570485

//    double intake = hardware::xbox.GetY(Joystick::JoystickHand::kLeftHand);
//    hardware::intake_arm.Set(-intake*.25);
  }

  void OperatorController::start()
  {

  }
}
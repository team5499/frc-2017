#include "OperatorController.h"

#include "../subsystems/Drivetrain.h"

namespace team5499
{
  void OperatorController::Step()
  {
    //Drivetrain
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

    //Climber
    bool climb = hardware::xbox.GetRawButton(3);
    if(climb)
      subsystems::climber.Set(1);
    else
      subsystems::climber.Set(0);


    //LEDS
    frc::SmartDashboard::PutNumber("Distance", hardware::intake_sensor.GetValue());
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
    //hardware::intake_arm.Set(-intake * .25);
    subsystems::gearmech.SetArm(-intake * .25);

    bool roller_intake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kRightHand);
    bool roller_intake_slow = hardware::xbox.GetTriggerAxis(
      Joystick::JoystickHand::kRightHand);
    bool roller_outtake = hardware::xbox.GetBumper(
      Joystick::JoystickHand::kLeftHand);

    if(roller_intake)
      //hardware::intake_roller.Set(0.6);
      subsystems::gearmech.SetRoller(0.6);
    else if(roller_intake_slow > 0.5)
      //hardware::intake_roller.Set(0.1);
      subsystems::gearmech.SetRoller(.1);
    else if(roller_outtake)
      //hardware::intake_roller.Set(-0.6);
      subsystems::gearmech.SetRoller(-0.6);
    else
      //hardware::intake_roller.Set(0);
      subsystems::gearmech.SetRoller(0);
  }
}
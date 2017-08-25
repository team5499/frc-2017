#include "TeleopController.h"

TeleopController::TeleopController()
:
throttle(Reference::throttle_port),
wheel(Reference::wheel_port),
xbox(Reference::xbox_port)
{
}
void TeleopController::Handle()
{
    //drivetrain
    double throttle_speed = throttle.GetRawAxis(1);
    double wheel_speed = wheel.GetRawAxis(0);
    if(!wheel.GetRawButton(8))
    {
        if(throttle_speed > 0)
            wheel *= 0.4;
        else
            wheel *= 0.25;
    }
    subsystems::drivetrain.DriveLR(throttle_speed + wheel_speed, throttle_speed - wheel_speed);

    //gearmech
    double intake = xbox.GetY(Joystick::JoystickHand::kLeftHand) * 0.40;
    bool roller_intake = xbox.GetBumper(Joystick::JoystickHand::kRightHand);
    double roller_intake_slow = xbox.GetTriggerAxis(Joystick::JoystickHand::kRighthand);
    bool roller_outtake = xbox.GetBumper(Joystick::JoystickHand::kLeftHand);

    subsystems::gearmech.SetArm(intake);
    if(roller_intake)
        subsystems::gearmech.SetRoller(0.6);
    else if(roller_intake_slow > 0.5)
        subsystems::gearmech.SetRoller(0.1);
    else if(roller_outtake)
        subsystems::gearmech.SetRoller(-0.6);
    else
        subsystems::gearmech.SetRoller(0);

    //climber
    bool climb = xbox.GetRawButton(3);
    bool climb_slow = xbox.GetRawButton(4);
    bool climb_reverse = xbox.GetBButton();

    if(climb)
        subsystems::climber.climb(1);
    else if(climb_slow)
        subsystems::climber.climb(0.2);
    else if(climb_reverse)
        subsystems::climber.climb(-1);
    else
        subsystems::climber.climb(0);
}
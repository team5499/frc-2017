#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController()
    :
    throttle(Reference::throttle),
    wheel(Reference::wheel),
    xbox(Reference::xbox)
{
    std::cout << "Initialized Operator Controller." << std::endl;
    
}

void OperatorController::handle()
{
    double vthrottle = throttle.GetRawAxis(1);
    double vwheel = wheel.GetRawAxis(0);
    if(!wheel.GetRawButton(8))
    {
      if(vthrottle > 0)
        vwheel *= 0.4;
      else
        vwheel *= 0.25;
    }
    Hardware::drivetrain.driveLR(vthrottle + vwheel, vthrottle - vwheel);

    bool roller_intake = xbox.GetBumper(Joystick::JoystickHand::kRightHand);
    bool roller_intake_slow = xbox.GetTriggerAxis(Joystick::JoystickHand::kRightHand);
    bool roller_outtake = xbox.GetBumper(Joystick::JoystickHand::kLeftHand);
    if(roller_intake)
      Hardware::gearmech.setRoller(0.6);
    else if(roller_intake_slow > 0.5)
      Hardware::gearmech.setRoller(0.1);
    else if(roller_outtake)
      Hardware::gearmech.setRoller(-0.6);
    else
     Hardware::gearmech.setRoller(0);

    bool climb = xbox.GetRawButton(3);
    if(climb)
      Hardware::climber.setSpeed(1);
    else
      Hardware::climber.setSpeed(0);

    if(xbox.GetRawButton(1))
    {
      Hardware::gearmech.setArm(0.91);
    }
    else if(xbox.GetRawButton(2))
    {
      Hardware::gearmech.setArm(2.53);
    }
}

void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
    Hardware::gearmech.enable();
}
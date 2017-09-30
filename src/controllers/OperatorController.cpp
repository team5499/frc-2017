#include "OperatorController.h"

namespace team5499
{
  void OperatorController::Start()
  {
  }
  void OperatorController::Handle()
  {
    
    //Drivetrain
    subsystems::drivetrain.Drive(subsystems::joysticks.getLeftValue(), subsystems::joysticks.getRightValue());
    //Gearmech
    subsystems::gearmech.SetRoller(subsystems::joysticks.getRollerValue());
    subsystems::gearmech.SetArm(subsystems::joysticks.getArmValue());

    if(subsystems::gearmech.GearDetected())
      subsystems::led.flash(100, 100, 100);
    //Climber
    subsystems::climber.SetClimber(subsystems::joysticks.getClimberValue());

  }
}
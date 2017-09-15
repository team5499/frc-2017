#include "OperatorController.h"

namespace team5499
{
  void OperatorController::Step()
  {
    
    //Drivetrain
    subsystems::drivetrain.Drive(subsystems::joysticks.getLeftValue(), subsystems::joysticks.getRightValue());
    //Gearmech
    subsystems::gearmech.SetRoller(subsystems::joysticks.getRollerValue());
    subsystems::gearmech.SetArm(subsystems::joysticks.getArmValue());
    //Climber
    subsystems::climber.SetClimber(subsystems::joysticks.getClimberValue());

  }
}
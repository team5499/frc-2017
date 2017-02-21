#include "OperatorController.h"

OperatorController::OperatorController(Hardware& hardware)
  :
  hardware(hardware)
{
}

void OperatorController::handle()
{
  double left = -hardware.controlBoard.xboxController.GetRawAxis(5);
  double right = hardware.controlBoard.xboxController.GetRawAxis(1);
  hardware.drivetrain.left1.Set(left);
  hardware.drivetrain.left2.Set(left);
  hardware.drivetrain.right1.Set(right);
  hardware.drivetrain.right2.Set(right);
  static int previousClimbButton = 0;
  if(hardware.controlBoard.xboxController.GetRawButton(1) && previousClimbButton == 0)
  {
    hardware.climber.climber.Set(!hardware.climber.climber.Get());
  }
  previousClimbButton = hardware.controlBoard.xboxController.GetRawButton(1);
}
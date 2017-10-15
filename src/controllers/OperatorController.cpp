#include "OperatorController.h"

namespace team5499
{
  void OperatorController::Start()
  {
    timer.Start();
    flash = false;
  }
  void OperatorController::Handle()
  {
    millis = timer.Get() * 1000;
    //Drivetrain
    subsystems::drivetrain.Drive(subsystems::joysticks.getLeftValue(), subsystems::joysticks.getRightValue());
    //Gearmech
    subsystems::gearmech.SetRoller(subsystems::joysticks.getRollerValue());
    subsystems::gearmech.SetArm(subsystems::joysticks.getArmValue());

    if(subsystems::gearmech.GearDetected())
      subsystems::led.flash(100, 100, 100);
    //Climber
    if(subsystems::joysticks.getClimberValue() == 1.0) {
      subsystems::climber.SetClimber(subsystems::joysticks.getClimberValue());
      flashLEDs();
    }

  }

  void OperatorController::flashLEDS() {
    if(millis % 150 == 0) {
      if(flash) {
        subsystems::led.setRGB(255, 0, 0);
        flash = !flash;
      } else {
        subsystems::led.setRGB(0, 255, 0);
        flash = !flash;
      }
    }
  }
}
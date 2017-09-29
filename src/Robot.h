#pragma once

#include <WPILib.h>
#include <iostream>
#include <CANTalon.h>
#include "controllers/OperatorController.h"
#include "controllers/AutoController.h"
#include "subsystems/Subsystems.h"

namespace team5499
{
  class Robot : public IterativeRobot
  {
  private:
    static OperatorController operatorController;
    static AutoController autoController;
  public:
    Robot();

    void RobotInit() override;
    void RobotPeriodic() override;

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;
  };
}

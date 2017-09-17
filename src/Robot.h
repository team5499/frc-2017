#pragma once

#include <WPILib.h>
#include <iostream>
#include <CANTalon.h>
#include "Reference.h"
#include "controllers/OperatorController.h"
#include "controllers/AutoController.h"

namespace team5499
{
  class Robot : public IterativeRobot
  {
  private:
  public:
    team5499::OperatorController operatorController;
    team5499::AutoController autoController;

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

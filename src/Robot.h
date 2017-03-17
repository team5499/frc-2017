#pragma once

#include <WPILib.h>
#include "Hardware.h"
#include "controllers/AutoController.h"
#include "controllers/OperatorController.h"
#include "autocommands/DriveDistanceCommand.h"
#include "autocommands/IntakeSetpointCommand.h"
#include "autocommands/TurnCommand.h"
#include "autocommands/AutoRoutine.h"

namespace team5499
{
  class Robot : public IterativeRobot
  {
  private:
    int autoIndex = 0;
  public:
    team5499::OperatorController operatorController;

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

#pragma once
#include <WPILib.h>
#include <iostream>

#include "TeleopController.h"

class Robot : public frc::IterativeRobot
{
private:
    TeleopController teleop;
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
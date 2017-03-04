#pragma once
#include <WPILib.h>

class Robot : public IterativeRobot
{
    private:

    public:
    Robot();

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

}
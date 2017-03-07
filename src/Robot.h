#pragma once
#include <WPILib.h>
#include "Reference.h"
#include "Hardware.h"
#include "controllers/OperatorController.h"

class Robot : public IterativeRobot
{
    private:

    OperatorController operatorController;
    

    public:
    Robot();

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

};


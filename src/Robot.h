#pragma once
#include <WPILib.h>
#include "Reference.h"
#include "Hardware.h"
#include "controllers/OperatorController.h"
#include "controllers/AutoController.h"
#include <iostream>

class Robot : public frc::IterativeRobot
{
    private:
        OperatorController operatorController;
        AutoController autoController;
    public:
        Robot();

        void DisabledInit() override;
        void DisabledPeriodic() override;
        
        void TeleopInit() override;
        void TeleopPeriodic() override;
        
        void AutonomousInit() override;
        void AutonomousPeriodic() override;

        //void TestInit() override;
        //void TestPeriodic() override;

    
};

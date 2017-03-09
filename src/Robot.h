#pragma once
#include <WPILib.h>
#include <iostream>
#include "CowLib/c/CowGyro.h"

class Robot : public frc::IterativeRobot
{
    private:
        CowLib::CowGyro gyroscope;
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

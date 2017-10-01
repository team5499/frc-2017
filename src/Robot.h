#pragma once

#include <WPILib.h>
#include <iostream>



namespace team5499 {
    
    class Robot() : public IternativeRobot
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
    }

}
#pragma once

#include <WPILib.h>
#include "controllers/OperatorController.h"
#include <iostream>

class Robot : public frc::IterativeRobot
{
private:
  // Disable copy constructors
  Robot(const Robot&) = delete;
  Robot& operator=(const Robot&) = delete;

  Hardware hardware;
  OperatorController operatorController;
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

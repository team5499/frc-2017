#include <iostream>
#include <WPILib.h>
#include "Hardware.h"

int main()
{
  auto lw = frc::LiveWindow::GetInstance();
  HAL_Report(HALUsageReporting::kResourceType_Framework,
             HALUsageReporting::kFramework_Simple);

  NetworkTable::GetTable("LiveWindow")->GetSubTable("~STATUS~")->PutBoolean(
          "LW Enabled", false);
  lw->SetEnabled(false);

  HAL_ObserveUserProgramStarting();

  std::cout << "Left motor value: " << team5499::Hardware::LeftDrive1.Get() << std::endl;

  while(true)
  {
    std::cout << "Running!" << std::endl;
  }
}
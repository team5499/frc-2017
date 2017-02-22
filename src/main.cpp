#include <iostream>
#include <WPILib.h>
#include <Internal/HardwareHLReporting.h>
#include <WPILibVersion.h>
#include "Hardware.h"

int main()
{
  frc::RobotState::SetImplementation(frc::DriverStation::GetInstance());
  frc::HLUsageReporting::SetImplementation(new frc::HardwareHLReporting());

  NetworkTable::SetNetworkIdentity("Robot");
  NetworkTable::SetPersistentFilename("/home/lvuser/networktables.ini");

  SmartDashboard::init();

  std::FILE* file = nullptr;
  file = std::fopen("/tmp/frc_versions/FRC_Lib_Version.ini", "w");

  if(file != nullptr)
  {
    std::fputs("C++", file);
    std::fputs(WPILibVersion, file);
    std::fclose(file);
  }

  auto lw = frc::LiveWindow::GetInstance();
  HAL_Report(HALUsageReporting::kResourceType_Framework,
             HALUsageReporting::kFramework_Simple);

  NetworkTable::GetTable("LiveWindow")->GetSubTable("~STATUS~")->PutBoolean(
          "LW Enabled", false);
  lw->SetEnabled(false);

  HAL_ObserveUserProgramStarting();

  std::cout << "Left motor value: " << team5499::Hardware::LeftDrive1.Get()
            << std::endl;

  while(true)
  {
    std::cout << "Running!" << std::endl;
  }
}
#include <iostream>
#include <WPILib.h>
#include <Internal/HardwareHLReporting.h>
#include <WPILibVersion.h>
#include "hardware.h"
#include "view.h"
#include "robot_state.h"
#include "make_robot_loop.h"

using namespace team5499;

void setup();

int main()
{
  setup();
  auto handler = [](robot_state&& state)
  {
    if(frc::RobotState::IsOperatorControl())
    {
      auto xbox_axis_view = view::axis_view(0);
      state.drive_speed_left = xbox_axis_view[1];
      state.drive_speed_right = xbox_axis_view[5];
    }
    return std::move(state);
  };
  auto robot_loop = make_robot_loop(handler);
  return robot_loop();
}

/**
 * Do a bunch of WPILib setup
 * This function is ripped from frc::RobotBase
 */
void setup()
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
}
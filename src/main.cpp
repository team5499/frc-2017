#include <signal.h>
#include <ucontext.h>
#include <iostream>
#include <WPILib.h>
#include <Internal/HardwareHLReporting.h>
#include <WPILibVersion.h>
#include <unistd.h>
#include "view.h"
#include "robot_state.h"
#include "make_robot_loop.h"

using namespace team5499;

void setup();

int main()
{
  setup();

  team5499::hardware::drive_left1.SetInverted(true);
  team5499::hardware::drive_left2.SetInverted(true);

  team5499::hardware::drive_left1.SetVoltageRampRate(10);
  team5499::hardware::drive_left2.SetVoltageRampRate(10);
  team5499::hardware::drive_right1.SetVoltageRampRate(10);
  team5499::hardware::drive_right2.SetVoltageRampRate(10);

  auto robot_loop = make_robot_loop(
    nullptr, // Disabled
    nullptr, // Auto
    [](robot_state&& state) // Teleop
    {
      auto xbox_axis_view = view::axis(0);
      state.drive_speed_left = xbox_axis_view[5];
      state.drive_speed_right = xbox_axis_view[1];
      return std::move(state);
    },
    nullptr // Test
  );
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
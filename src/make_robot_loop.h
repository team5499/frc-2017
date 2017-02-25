#pragma once
#include "robot_state.h"

namespace team5499
{
  /*
   * Constructs a robot robot loop given a handler lambda(robot_state&& state) -> robot_state&& state
   * @param handler The user handler
   * @return The robot loop lambda
   * TODO: accept handlers for teleop, auto, etc.
   */
  template<typename F>
  auto make_robot_loop(F& handler)
  {
    team5499::robot_state state;
    return [state = std::move(state), handler]()
    mutable
    {
      auto lw = frc::LiveWindow::GetInstance();
      HAL_Report(HALUsageReporting::kResourceType_Framework,
                 HALUsageReporting::kFramework_Simple);

      NetworkTable::GetTable("LiveWindow")->GetSubTable("~STATUS~")->PutBoolean(
              "LW Enabled", false);
      lw->SetEnabled(false);

      HAL_ObserveUserProgramStarting();

      std::cout << "Starting robot loop!" << std::endl;
      while(true)
      {
        if(frc::RobotState::IsEnabled())
        {
          state = handler(std::move(state));
          state.apply();
        }
      }
      return 0;
    };
  }
}
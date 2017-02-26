#pragma once

#include "robot_state.h"

namespace team5499
{
  /**
   * Template specialization to let make_robot_loop accept nullptr parameters
   */
  template<typename T>
  robot_state&& call_handler(T&& handler, robot_state&& state)
  {
    return std::move(handler(std::move(state)));
  }

  /**
   * Template specialization to let make_robot_loop accept nullptr parameters
   */
  template<>
  robot_state&& call_handler(nullptr_t&&, robot_state&& state)
  {
    return std::move(state);
  }

  /*`
   * Constructs a robot robot loop given a handler lambda(robot_state&& state) -> robot_state&& state
   * @param handler The user handler
   * @return The robot loop lambda
   */
  template<typename T_AutoHandler, typename T_TeleopHandler, typename T_DisabledHandler, typename T_TestHandler>
  auto make_robot_loop(T_DisabledHandler&& disabledHandler,
                       T_AutoHandler&& autoHandler,
                       T_TeleopHandler&& teleopHandler,
                       T_TestHandler&& testHandler)
  {
    team5499::robot_state state;
    return [state = std::move(state),
            disabledHandler, autoHandler, teleopHandler, testHandler]()
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
        if(frc::RobotState::IsDisabled())
        {
          state = call_handler(std::forward<T_DisabledHandler>(disabledHandler),
                               std::move(state));
        }
        else if(frc::RobotState::IsAutonomous())
        {
          state = call_handler(std::forward<T_AutoHandler>(autoHandler),
                               std::move(state));
        }
        else if(frc::RobotState::IsOperatorControl())
        {
          state = call_handler(std::forward<T_TeleopHandler>(teleopHandler),
                               std::move(state));
        }
        else if(frc::RobotState::IsTest())
        {
          state = call_handler(std::forward<T_TestHandler>(testHandler),
                               std::move(state));
        }
        state.apply();
      }
      return 0;
    };
  }
}
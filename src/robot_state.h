#pragma once

#include "hardware.h"

namespace team5499
{
  /**
   * Representation of the robot's hardware output.
   * TODO: create an interface class with apply.
   */
  class robot_state
  {
  private:
    robot_state(const robot_state&) = delete;
    robot_state& operator=(const robot_state&) = delete;
  public:
    robot_state() = default;
    robot_state(robot_state&&) = default;
    robot_state& operator=(robot_state&&) = default;

    double drive_speed_left;
    double drive_speed_right;
    double intake_arm_speed;
    double intake_roller_speed;
    double climber_speed;

    /**
     * Applies the state to real hardware.
     */
    void apply()
    {
      hardware::drive_left1.Set(drive_speed_left);
      hardware::drive_left2.Set(drive_speed_left);
      hardware::drive_right1.Set(drive_speed_right);
      hardware::drive_right2.Set(drive_speed_right);

      hardware::intake_arm.Set(intake_arm_speed);
      hardware::intake_roller.Set(intake_roller_speed);

      hardware::climber.Set(climber_speed);
    }
  };
}
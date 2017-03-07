#pragma once

#include <WPILib.h>

namespace team5499
{
  class Reference
  {
  public:
    //Sensors
    const uint32_t gyro_port = 0;
    //Talons
    const static int drive_left1_port = 1;
    const static int drive_left2_port = 2;
    const static int drive_right1_port = 3;
    const static int drive_right2_port = 4;
    const static int intake_arm_port = 6;
    const static int intake_roller_port = 7;
    const static int climber_port = 5;
    //Controllers
    const static int wheel_port = 0;
    const static int throttle_port = 1;
    const static int xbox_port = 2;
  };
}
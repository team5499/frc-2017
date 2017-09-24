#pragma once

namespace team5499
{
  class Reference
  {
  public:
    //Talons
    const static int drive_left1_port = 1;
    const static int drive_left2_port = 2;
    const static int drive_right1_port = 3;
    const static int drive_right2_port = 4;
    const static int arm_port = 5;
    const static int roller_port = 6;
    const static int climber_left_port = 7;
    const static int climber_right_port = 8;
    //Controllers
    const static int xbox_port = 0;
    const static int driver_port = 1;
    const static int throttle_port = 2;
    const static int wheel_port = 3;
    //Encoders
    const static int right_encoder_port1 = 0;
    const static int right_encoder_port2 = 1;
    const static int left_encoder_port1 = 2;
    const static int left_encoder_port2 = 3;
    //PID
    constexpr static double kP = 0.1;
    constexpr static double kI = 0.0;
    constexpr static double kD = 0.0;
  };
}
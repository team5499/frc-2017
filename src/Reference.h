#pragma once

#include <iostream>
#include <fstream>
#include <streambuf>

#include <json/json.h>
#include <json/json-forwards.h>

namespace team5499
{
  class Reference
  {
  public:
    //Talons
    const static int front_left_port = 1;
    const static int back_left_port = 2;
    const static int front_right_port = 3;
    const static int back_right_port = 4;
    const static int arm_port = 5;
    const static int roller_port = 6;
    const static int climber1_port = 7;
    const static int climber2_port = 8;
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

    constexpr static double roller_speed = 0.5;
    constexpr static double PI = 3.1415926;
    constexpr static double climb_speed = 0.75;

    constexpr static double distance_per_pulse = 0.04908738438;// (4*PI)/256
  };
}
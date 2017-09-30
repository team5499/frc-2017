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

    constexpr static double distance_per_pulse = 0.04908738438;// (4*PI)/256
    //PID
    static double kP;
    static double kI;
    static double kD;
    static double kAP;//angle
    static double kAI;//angle
    static double kAD;//angle
    //Angle
    constexpr static double center_wheel_dist_inches = 25.0;
    constexpr static double pi = 3.14159265358979;

    //JSON

    static void updateVariables()
    {
      std::ifstream json_file("/home/lvuser/variables.json");
      Json::Value root;
      json_file >> root;

      Reference::kP = root.get("kP", 0.0).asDouble();
      Reference::kI = root.get("kI", 0.0).asDouble();
      Reference::kD = root.get("kD", 0.0).asDouble();

      Reference::kAP = root.get("kAP", 0.0).asDouble();
      Reference::kAI = root.get("kAI", 0.0).asDouble();
      Reference::kAD = root.get("kAD", 0.0).asDouble();

      json_file.close();
    }
  };
}
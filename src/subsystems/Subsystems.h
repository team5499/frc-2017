#pragma once

#include "Drivetrain.h"
#include "Gearmech.h"
#include "Climber.h"
#include "Joysticks.h"
#include "HandlePID.h"

namespace team5499
{
  class subsystems
  {
  public:
    static bool is_initialized;
    subsystems()
    {
      if(!subsystems::is_initialized)
      {
      std::cout << "Initializing HAL... ";
      if(!HAL_Initialize(0))
      {
        std::cerr << "FATAL ERROR: HAL could not be initialized" << std::endl;
        exit(-1);
      }
      HAL_Report(HALUsageReporting::kResourceType_Language,
                 HALUsageReporting::kLanguage_CPlusPlus);

      std::cout << "HAL initialized" << std::endl;
      subsystems::is_initialized = true;
      }
    }
    static Drivetrain drivetrain;
    static Gearmech gearmech;
    static Climber climber;
    static Joysticks joysticks;
    static HandlePID pid;
  };
  static subsystems _init_subsystems;
}
#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>

namespace team5499
{
  class Hardware
  {
  private:
    static bool HAL_initialized;
  public:
    Hardware()
    {
      if(!HAL_initialized)
      {
        std::cout << "Initializing HAL" << std::endl;
        if(!HAL_Initialize(0))
        {
          std::cerr << "FATAL ERROR: HAL could not be initialized" << std::endl;
          exit(-1);
        }
        HAL_Report(HALUsageReporting::kResourceType_Language,
                   HALUsageReporting::kLanguage_CPlusPlus);
        HAL_initialized = true;
      }
    }

    static CANTalon LeftDrive1, LeftDrive2, RightDrive1, RightDrive2;
  };

  static Hardware _init_hardware;
}
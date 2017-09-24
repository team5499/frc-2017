#pragma once

#include <WPILib.h>

namespace team5499
{
    class RobotInit
    {
    private:
        static int init_counter;
    public:
        RobotInit()
        {
          if(init_counter++ == 0)
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
          }
        }
    };
    static RobotInit _init_robot;
}
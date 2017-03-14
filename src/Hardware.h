#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include <team1538/CowAlphaNum.h>
#include "subsystems/LED.h"
#include "Reference.h"

namespace team5499
{
  /**
   * Contains static objects for all robot hardware
   */
  class hardware
  {
  private:
    static bool _HAL_initialized;
  public:
    /**
     * Initializes the HAL on first construction
     */
    hardware()
    {
      if(!_HAL_initialized)
      {
        std::cout << "Initializing HAL" << std::endl;
        if(!HAL_Initialize(0))
        {
          std::cerr << "FATAL ERROR: HAL could not be initialized" << std::endl;
          exit(-1);
        }
        HAL_Report(HALUsageReporting::kResourceType_Language,
                   HALUsageReporting::kLanguage_CPlusPlus);
        _HAL_initialized = true;

        std::cout << "HAL initialized" << std::endl;
      }
    }

    //Talons
    static CANTalon drive_left1, drive_left2, drive_right1, drive_right2;
    static CANTalon intake_arm;
    static CANTalon intake_roller;
    static CANTalon climber;
    //Sticks
    static Joystick wheel;
    static Joystick throttle;
    static XboxController xbox;
    //Sensors
    //static CowLib::CowGyro gyro;
    static CowLib::CowAlphaNum mxp_display;
    //LEDs
    static LED leds;
  };

  /**
   * Forces a construction of hardware (and initialization of the HAL)
   */
  static hardware _init_hardware;
}
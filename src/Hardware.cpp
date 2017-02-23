#include "hardware.h"

/**
 * Static initializations for team5499::hardware
 */
bool team5499::hardware::_HAL_initialized = false;
CANTalon team5499::hardware::drive_left1(1);
CANTalon team5499::hardware::drive_left2(2);
CANTalon team5499::hardware::drive_right1(3);
CANTalon team5499::hardware::drive_right2(4);
#include "hardware.h"

/**
 * Static initializations for hardware
 */
namespace team5499
{
  bool hardware::_HAL_initialized = false;
  CANTalon hardware::drive_left1(Reference::drive_left1_port);
  CANTalon hardware::drive_left2(Reference::drive_left2_port);
  CANTalon hardware::drive_right1(Reference::drive_right1_port);
  CANTalon hardware::drive_right2(Reference::drive_right2_port);

  CANTalon hardware::arm(Reference::arm_port);
  CANTalon hardware::roller(Reference::roller_port);

  CANTalon hardware::climber_left(Reference::climber_left_port);
  CANTalon hardware::climber_right(Reference::climber_right_port);

  XboxController hardware::driver(Reference::driver_port);
}
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
  CANTalon hardware::intake_arm(Reference::intake_arm_port);
  CANTalon hardware::intake_roller(Reference::intake_roller_port);
  CANTalon hardware::climber(Reference::climber_port);

  Joystick hardware::wheel(Reference::wheel_port);
  Joystick hardware::throttle(Reference::throttle_port);
  XboxController hardware::xbox(Reference::xbox_port);

  AnalogInput hardware::intake_pot(0);
  Encoder hardware::drive_encoder(10, 11);
  team1538::CowGyro hardware::mxp_gyro;
  team1538::CowAlphaNum hardware::mxp_display;

  LED hardware::leds;
}
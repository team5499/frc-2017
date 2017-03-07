#include "hardware.h"

/**
 * Static initializations for team5499::hardware
 */
bool team5499::hardware::_HAL_initialized = false;
CANTalon team5499::hardware::drive_left1(Reference::drive_left1_port);
CANTalon team5499::hardware::drive_left2(Reference::drive_left2_port);
CANTalon team5499::hardware::drive_right1(Reference::drive_right1_port);
CANTalon team5499::hardware::drive_right2(Reference::drive_right2_port);
CANTalon team5499::hardware::intake_arm(Reference::intake_arm_port);
CANTalon team5499::hardware::intake_roller(Reference::intake_roller_port);
CANTalon team5499::hardware::climber(Reference::climber_port);

Joystick team5499::hardware::wheel(Reference::wheel_port);
Joystick team5499::hardware::throttle(Reference::throttle_port);
XboxController team5499::hardware::xbox(Reference::xbox_port);

//CowLib::CowGyro team5499::hardware::gyro(Reference::gyro_port);
#include "Hardware.h"

// Static initializations for team5499::Hardware
bool team5499::Hardware::HAL_initialized = false;
CANTalon team5499::Hardware::LeftDrive1(1);
CANTalon team5499::Hardware::LeftDrive2(2);
CANTalon team5499::Hardware::RightDrive1(3);
CANTalon team5499::Hardware::RightDrive2(4);
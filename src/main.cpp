#include "RobotInit.h" // has to be included first in any files with static initialization
#include "Robot.h"

int team5499::RobotInit::init_counter = -1; // this is used to ensure the HAL is initialized only once, and before any static initializations occur

int main()
{
  static team5499::Robot robot;
  robot.StartCompetition();
  return 0;
}
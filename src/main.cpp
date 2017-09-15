#include "Robot.h"

int main()
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
  static team5499::Robot robot;
  robot.StartCompetition();
  return 0;
}
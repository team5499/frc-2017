#include "Robot.h"
#include "RobotInit.h"

int team5499::RobotInit::init_counter = -1;

int main() {
    static team5499::Robot robot;
    robot.StartCompetition();
    return 0;
}
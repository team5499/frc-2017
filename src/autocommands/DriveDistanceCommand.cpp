#include "DriveDistanceCommand.h"

namespace team5499
{
    DriveDistanceCommand::DriveDistanceCommand(double dist)
    :
    distance(dist)
    {
    }
    void DriveDistanceCommand::Init()
    {
        PIDHandle::enableDrive();
        PIDHandle::changeLeftSetPoint(distance);
        PIDHandle::changeRightSetPoint(distance);
        std::cout << "drive init" << std::endl;
    }
    void DriveDistanceCommand::Handle()
    {
        PIDHandle::step();
    }
    bool DriveDistanceCommand::isFinished()
    {
        if(PIDHandle::errorMinimizedLeft() && PIDHandle::errorMinimizedRight())
        {
            PIDHandle::disableDrive();
            return true;
        }
    }
}
#include "DriveStraightCommand.h"

namespace team5499
{
    DriveStraightCommand::DriveStraightCommand(int dist)
        :
        distance(dist)
    {
        time = 0;
    }

    void DriveStraightCommand::init()
    {
    }

    void DriveStraightCommand::step()
    {
        Drivetrain::driveLR(1,1);
        ++time;
    }

    bool DriveStraightCommand::finished()
    {
        if(time>distance)
            Drivetrain::driveLR(0,0);
        return (time>distance);
    }
}
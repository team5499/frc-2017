#include "TurnCommand.h"

namespace team5499
{
    TurnCommand::TurnCommand(double a)
    :
    angle(a)
    {
    }
    void TurnCommand::Init()
    {
        PIDHandle::changeAngle(angle);
        //PIDHandle::enableAngle();
    }
    void TurnCommand::Handle()
    {
        PIDHandle::step();
    }
    bool TurnCommand::isFinished()
    {
        if(PIDHandle::errorMinimizedAngle())
        {
            //PIDHandle::disableAngle();
            return true;
        }
    }
}
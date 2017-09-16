#include "MoveGearmechCommand.h"

namespace team5499
{
    MoveGearmechCommand::MoveGearmechCommand(double val)
    :
    value(val)
    {
    }
    void MoveGearmechCommand::Init()
    {
        subsystems::gearmech.SetArm(value);
    }
    void MoveGearmechCommand::Handle()
    {
    }
    bool MoveGearmechCommand::isFinished()
    {
        return (subsystems::gearmech.GetArmVoltage() > (10*value)-0.5);
    }
}
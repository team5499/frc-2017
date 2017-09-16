#pragma once

#include "GenericAutoCommand.h"

namespace team5499
{
    class MoveGearmechCommand : public GenericAutoCommand
    {
    private:
        double value;
    public:
        MoveGearmechCommand(double val);
        void Handle() override;
        void Init() override;
        bool isFinished() override;
    };
}
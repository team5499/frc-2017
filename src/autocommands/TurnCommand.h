#pragma once

#include "GenericAutoCommand.h"

namespace team5499
{
    class TurnCommand : public GenericAutoCommand
    {
    private:
        double angle;
    public:
        TurnCommand(double a);
        void Handle() override;
        void Init() override;
        bool isFinished() override;
    };
}
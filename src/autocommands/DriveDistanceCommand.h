#pragma once

#include "GenericAutoCommand.h"

namespace team5499
{
    class DriveDistanceCommand : public GenericAutoCommand
    {
    private:
        double distance;
    public:
        DriveDistanceCommand(double dist);
        void Handle() override;
        void Init() override;
        bool isFinished() override;
    };
}
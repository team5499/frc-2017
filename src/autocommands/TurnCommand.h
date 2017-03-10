#pragma once
#include <WPILib.h>
#include "GenericCommand.h"

class TurnCommand : public GenericCommand
{
    private:
        int angle;
        double lastangle;
        double va;
        frc::PIDController* distanceController;
        frc::PIDController* angleController;
        ManualPIDOut* distOut;
        ManualPIDOut* angleOut;
    public:
        TurnCommand(int degrees);
        void init();
        void step();
        bool finished();
};
#pragma once
#include <WPILib.h>
#include "GenericCommand.h"

class TurnCommand : public GenericCommand
{
    private:
        int angle;
        frc::PIDController* distanceController;
        frc::PIDController* angleController;
        ManualPIDOut* distOut;
        ManualPIDOut* angleOut;
    public:
        TurnCommand(Reference* r, Hardware* h, int degrees);
        void init();
        void step();
        bool finished();
};
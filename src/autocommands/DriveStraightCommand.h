#pragma once
#include <WPILib.h>
#include "GenericCommand.h"

class DriveStraightCommand : public GenericCommand
{
    private:
        int distance;
        double lastangle;
        double va;
        frc::PIDController* distanceController;
        frc::PIDController* angleController;
        ManualPIDOut* distOut;
        ManualPIDOut* angleOut;
    public:
        DriveStraightCommand(int distance);
        void init();
        void step();
        bool finished();
};
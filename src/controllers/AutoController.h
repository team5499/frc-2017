#pragma once

#include <WPILib.h>

#include "../subsystems/Subsystems.h"
#include "GenericController.h"
#include "../subsystems/PID.h"
#include "../auto_commands/Routine.h"

//Auto commands
#include "../auto_commands/DoNothingCommand.h"
#include "../auto_commands/DriveCommand.h"
#include "../auto_commands/TurnCommand.h"
#include "../auto_commands/GearmechCommand.h"

namespace team5499
{
    class AutoController : public GenericController
    {
    private:
        Routine left;
        Routine center;
        Routine right;
        Routine test;

        Routine *currentRoutine;

        int autoMode;
    public:
        AutoController();
        void Start() override;
        void Handle() override;
        void reset();
    };
}
#pragma once

#pragma once

#include "../subsystems/Subsystems.h"
#include "GenericController.h"
#include "../subsystems/PID.h"
#include "../auto_commands/Routine.h"

//Auto commands
#include "../auto_commands/DoNothingCommand.h"
#include "../auto_commands/DriveCommand.h"

namespace team5499
{
    class AutoController : public GenericController
    {
    private:
        Routine center;
    public:
        AutoController();
        void Start() override;
        void Handle() override;
        void reset();
    };
}
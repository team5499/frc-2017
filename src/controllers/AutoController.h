#pragma once

#pragma once

#include "../subsystems/Subsystems.h"
#include "../subsystems/HandlePID.h"
#include "GenericController.h"

namespace team5499
{
    class AutoController : public GenericController
    {
    private:
        int step_now;
        double time_now;
        int routine;
    public:
        AutoController();
        void Step() override;  
    };
}
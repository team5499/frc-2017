#pragma once

#include "WPILib.h"
#include <iostream>
#include "GenericController.h"
#include "../Reference.h"

#include "../actions/Routine.h"
#include "../subsystems/Subsystems.h"

#include "../actions/GenericAction.h"
#include "../actions/DriveAction.h"
#include "../actions/GearmechAction.h"

namespace team5499 {
    class AutoController : public GenericController {
    private:
        Routine* currentRoutine;
        Routine center, left, right;

        int autoVerison;
    public:
        AutoController();
        void Start() override;
        void Handle() override;
        void Reset();
    };
}
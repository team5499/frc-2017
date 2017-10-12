#pragma once

#include <iostream>
#include <vector>

#include "../Reference.h"
#include "../subsystems/Subsystems.h"

#include "GenericAction.h"

namespace team5499 {
    class Routine {
    private: 
        int step_number;
        GenericAction *current_action;
        std::vector<GenericAction*> actions;

        bool advanceRoutine();
    public:
        Routine();
        void start();
        void handle();
        void reset();
        void append(GenericAction* action) {
            actions.push_back(action);
            current_action = actions.at(0);
        }
    };
}
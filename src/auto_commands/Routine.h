#pragma once

#include <iostream>
#include <vector>

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
    class Routine
    {
    private:
        int step_number;
        GenericCommand *current_command;
        std::vector<GenericCommand*> commands;

        bool advanceRoutine();
    public:
        Routine();
        void start();
        void handle();
        void addCommand(GenericCommand* command) { commands.push_back(command); current_command = commands.at(0); }

        void reset();
    };
}
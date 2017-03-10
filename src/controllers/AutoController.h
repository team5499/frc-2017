#pragma once
#include <WPILib.h>
#include "GenericController.h"
#include "../autocommands/GenericCommand.h"
#include "../autocommands/Routine.h"
#include <iostream>

class AutoController : public GenericController
{
    private:
        Routine autoRoutine;
        GenericCommand* currCommand;

        bool finished = false;
    public:
        AutoController();
        void handle();
        void start();
};
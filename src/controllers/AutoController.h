#pragma once
#include <WPILib.h>
#include "GenericController.h"
#include "../autocommands/GenericCommand.h"
#include "../autocommands/Routine.h"
#include <iostream>

class AutoController : public GenericController
{
    private:
        Reference* r;
        Hardware* h;

        Routine autoRoutine;
        GenericCommand* currCommand;

        bool finished = false;
    public:
        AutoController(Reference* ref, Hardware* hardware);
        void handle();
        void start();
};
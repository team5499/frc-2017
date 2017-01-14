#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"
#include "GenericController.h"
#include "../autocommands/GenericCommand.h"
#include <iostream>

class AutoController : public GenericController
{
    private:
        Reference* r;
        Hardware* h;
    public:
        AutoController(Reference* ref, Hardware* hardware);
        void handle();
        void start();
};
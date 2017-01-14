#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"

class GenericController
{
    private:
        Reference* ref;
        Hardware* hardware;
    public:
        virtual ~GenericController() {};
        virtual void handle() = 0;
        virtual void start() = 0;
};

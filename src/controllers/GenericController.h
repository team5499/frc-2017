#pragma once
#include <WPILib.h>
#include "../Hardware.h"

class GenericController
{
    private:
    
    public:
        virtual ~GenericController() {};
        virtual void handle() = 0;
        virtual void start() = 0;
};
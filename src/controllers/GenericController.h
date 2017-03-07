#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../subsystems/Climber.h"
#include "../subsystems/Gearmech.h"

class GenericController
{
    private:
    
    public:
        virtual ~GenericController() {};
        virtual void handle() = 0;
        virtual void start() = 0;
};
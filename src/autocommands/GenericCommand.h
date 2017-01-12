#pragma once
#include <WPILib.h>
#include "../Robot.h"

class GenericCommand
{
private:
    Robot* bot;
public:
    virtual ~GenericCommand() {};
    virtual void init() = 0;
    virtual void step() = 0;
    virtual bool finished() = 0;
};

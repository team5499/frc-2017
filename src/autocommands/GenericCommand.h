#pragma once
#include <WPILib.h>
#include "../Reference.h"
#include "../Hardware.h"

class GenericCommand
{
protected:
public:
    virtual ~GenericCommand() {};
    virtual void init() = 0;
    virtual void step() = 0;
    virtual bool finished() = 0;
};

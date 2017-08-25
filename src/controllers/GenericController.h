#pragma once

class GenericController
{
public:
    virtual ~GenericController() {};
    virtual void Handle() = 0;
};
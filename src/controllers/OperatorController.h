#pragma once
#include "GenericController.h"
#include <iostream>

using namespace team5499;

class OperatorController : public GenericController
{
    private:
    
    public:
        OperatorController();

        void handle();
        void start();

};


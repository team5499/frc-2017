#pragma once
#include "GenericController.h"
#include <iostream>
#include "WPILib.h"
#include "../subsystems/Subsystems.h" 
#include "../Reference.h"

namespace team5499 {
    class OperatorController : public GenericController {
    private:
        Timer timer;
        int millis;
        bool random;
    public:
        void Start() override;
        void Handle() override;
    };
}
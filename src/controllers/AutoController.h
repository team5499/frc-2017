#pragma once

#include "GenericController.h"
#include "WPILib.h"
#include <iostream>
#include "../subsystems/Subsystems.h"


namespace team5499 {
    class AutoController : public GenericController {
    public:
        void Start() override;
        void Handle() override;
    };
}
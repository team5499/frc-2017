#pragma once

#pragma once

#include "../subsystems/Subsystems.h"
#include "GenericController.h"

namespace team5499
{
    class AutoController : public GenericController
    {
    private:
    public:
        void Handle() override;  
    };
}
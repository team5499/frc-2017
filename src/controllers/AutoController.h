#pragma once

#include <WPILib.h>

#include "GenericController.h"

namespace team5499
{
    class AutoController : public GenericController
    {
    private:
    public:
        AutoController();
        void Start() override;
        void Handle() override;
    };
}
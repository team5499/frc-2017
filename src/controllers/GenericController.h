#pragma once
#include "WPILib.h"
#include "../Reference.h"

namespace team5499 {
    class GenericController {
    private:
        Reference* ref;
        // Hardware* hardware;
    public:
        virtual ~GenericController() {};
        virtual void Handle() = 0;
        virtual void Start() = 0;
    };
}
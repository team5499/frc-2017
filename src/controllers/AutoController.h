#pragma once

#include "GenericController.h"


namespace team5499 {
    class AutoController : public GenericController {
    public:
        void Start() override;
        void Handle() override;
    };
}
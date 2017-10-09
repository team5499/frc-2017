#pragma once

namespace team5499 {
    class GenericController {
    public:
        virtual ~GenericController() {};
        virtual void Handle() = 0;
        virtual void Start() = 0;
    };
}
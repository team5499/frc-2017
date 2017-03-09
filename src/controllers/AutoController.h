#pragma once
#include <WPILib.h>
#include "../Hardware.h"
#include "../Reference.h"
#include "../autocommands/Routine.h"
#include "../autocommands/GenericCommand.h"
#include "GenericController.h"

namespace team5499
{
    class AutoController : public GenericController
    {
        private:
            Routine routine;
            GenericCommand* currentCommand;
        public:
            AutoController(Routine r);

            void handle();
            void start();
    };
}
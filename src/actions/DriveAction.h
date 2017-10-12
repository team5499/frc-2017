#pragma once

#include "GenericAction.h"

namespace team5499 {
    class DriveAction : public GenericAction {
        private:
            double start_time;
        public:
            DriveAction(double start, double out)
            :
            GenericAction(out),
            start_time(start)
            {
            
            }

            void Start() override {
                GenericAction::Start();
            }

            void Handle() {
                subsystems::driveTrain.drive(0.3, 0.3);
            }

            bool isFinished() override {
                return GenericAction::isFinished();
            }
            
            void reset() {};
        };
}
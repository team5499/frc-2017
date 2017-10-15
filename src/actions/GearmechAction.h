#include "GenericAction.h"

namespace team5499 {
    class GearmechAction : public GenericAction {
    private:
        double start_time;
        bool direction; // true = up, false = down
    public:
        GearmechAction(double start, double out, bool upDown)
        :
        GenericAction(out),
        start_time(start),
        direction(upDown)
        {

        }

        void Start() override
         {
            GenericAction::Start();
        }

        void Handle() {
            if(direction) {
                subsystems::gearMech.SetArm(-0.2);
            }
            else {
                subsystems::gearMech.SetArm(0.2);
            }
        }

        bool isFinished() override {
            return GenericAction::isFinished();
        }

        void reset() {

        }

    };
}
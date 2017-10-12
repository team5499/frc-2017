#include "Routine.h"

namespace team5499 {
    Routine::Routine()
    :
    step_number(0)
    {
    }

    void Routine::start() {
        current_action -> Start();
    }

    void Routine::handle() {
        if (current_action->isFinished()) {
            subsystems::driveTrain.stop();
            if(!advanceRoutine) return;
        }
        else current_action -> Handle();
 
    }

    bool Routine::advanceRoutine() {
        if(!(step_number + 1 < actions.size())) {
            return false;
        }
        step_number++;
        current_action = actions.at(step_number);
        current_action -> Handle();

        return true;
    }

    void Routine::reset() {
        step_number = 0;
        for(int i = 0; i < actions.size(); i++) {
            actions.at(i)->reset();
        }
        current_action = actions.at(0);
    }
}
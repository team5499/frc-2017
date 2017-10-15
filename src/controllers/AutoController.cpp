#include "AutoController.h"

namespace team5499 {
    AutoController::AutoController()
    :
    center(),
    left(),
    right(),
    autoVerison(0)
    {
        center.append(new DriveAction(1, 60));
        center.append(new GearmechAction(40, 80, false));
    }


    void AutoController::Start() {
        switch(autoVerison) {
            case 0:
                currentRoutine = &center;
                break;
            case 1:
                currentRoutine = &left;
                break;
            case 2:
                currentRoutine = &right;
                break;
        }
        currentRoutine -> start();
    }

    void AutoController::Handle() {
        currentRoutine -> handle();
    }

    void AutoController::Reset() {
        center.reset();
        left.reset();
        right.reset();
    }
}
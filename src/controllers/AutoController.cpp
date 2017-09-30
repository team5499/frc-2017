#include "AutoController.h"

namespace team5499
{
    AutoController::AutoController()
    :
    left(),
    center(),
    right()
    {
        // left auto routine
        // center auto routine
        center.addCommand(new DriveCommand(80, 60));
        center.addCommand(new GearmechCommand(1, GearmechCommand::Direction::DOWN));
        // right auto routine
    }
    void AutoController::Start()
    {
        center.start();
    }
    void AutoController::Handle()
    {
        center.handle();
    }
    void AutoController::reset()
    {
        center.reset();
    }
}
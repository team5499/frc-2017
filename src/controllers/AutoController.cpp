#include "AutoController.h"

namespace team5499
{
    AutoController::AutoController()
    :
    center()
    {
        center.addCommand(new DriveCommand(80, 80));
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
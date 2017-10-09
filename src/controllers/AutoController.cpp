#include "AutoController.h"

namespace team5499
{
    AutoController::AutoController()
    :
    left(),
    center(),
    right(),
    test(),
    autoMode(1)
    {
        // left auto routine
        left.addCommand(new DoNothingCommand(1));
        // center auto routine
        center.addCommand(new DriveCommand(4, 80));
        center.addCommand(new GearmechCommand(1, GearmechCommand::Direction::DOWN));
        center.addCommand(new GearmechCommand(1, GearmechCommand::Direction::NONE));
        center.addCommand(new DriveCommand(2, -40));
        // right auto routine
        right.addCommand(new DoNothingCommand(1));
        // test auto routine
        test.addCommand(new DoNothingCommand(1));

        //smart dashboard
        SmartDashboard::PutNumber("automode", 1);
    }
    void AutoController::Start()
    {
        autoMode = SmartDashboard::GetNumber("automode", 1);
        switch(autoMode)
        {
            case 0:
                currentRoutine = &left;
                break;
            case 1:
                currentRoutine = &center;
                break;
            case 2:
                currentRoutine = &right;
                break;
            case 3:
                currentRoutine = &test;
                break;
            default:
                std::cout << "non legit auto mode selected!" << std::endl;
                break;
        }
        currentRoutine->start();
    }
    void AutoController::Handle()
    {
        currentRoutine->handle();
    }
    void AutoController::reset()
    {
        left.reset();
        center.reset();
        right.reset();
        test.reset();
    }
}
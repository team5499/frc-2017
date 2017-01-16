#include "TurnCommand.h"

TurnCommand::TurnCommand(Reference* ref, Hardware* hardware, int degrees)
    :
    angle(degrees)
{
    r = ref;
    h = hardware;
    angleOut = &(h->angleOut);
    distOut = &(h->distOut);
    distanceController = &(h->distanceController);
    angleController = &(h->angleController);
    h->changeAngle(angle);
    h->updateControllerPoints();
}

void TurnCommand::init()
{

}

void TurnCommand::step()
{
    double cvelocity = distOut->getOut();
    double cangle = angleOut->getOut();
    h->drivetrain.driveLR(cvelocity+cangle, cvelocity-cangle);
}

bool TurnCommand::finished()
{
    // Check if controllers are on target and robot is sufficiently stationary
    if (std::fabs(h->dist.GetRate()) < r->kVd && std::fabs(distanceController->GetError()) < r->kEd
    && std::fabs(h->gyroscope.GetRate()) < r->kVa && std::fabs(angleController->GetError()) < r->kEa) {
        return true;
    }
    else {
        return false;
    }
}
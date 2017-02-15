#include "DriveStraightCommand.h"

DriveStraightCommand::DriveStraightCommand(Reference* ref, Hardware* hardware, int dist)
    :
    distance(dist)
{
    r = ref;
    h = hardware;
    angleOut = &(h->angleOut);
    distOut = &(h->distOut);
    distanceController = &(h->distanceController);
    angleController = &(h->angleController);
    h->changeDistance(distance);
    h->updateControllerPoints();
}

void DriveStraightCommand::init()
{
    distanceController->Enable();
    angleController->Enable();
}

void DriveStraightCommand::step()
{
    double a = h->gyroscope.GetAngle();
    va = a-lastangle;
    lastangle = a;
    double cvelocity = distOut->getOut();
    double cangle = angleOut->getOut();
    h->drivetrain.driveLR(cvelocity+cangle, cvelocity-cangle);
}

bool DriveStraightCommand::finished()
{
    // Check if controllers are on target and robot is sufficiently stationary
    if (std::fabs(h->dist.GetRate()) < r->kVd && std::fabs(distanceController->GetError()) < r->kEd
    && std::fabs(va) < r->kVa && std::fabs(angleController->GetError()) < r->kEa) {
        distanceController->Disable();
        angleController->Disable();
        return true;
    }
    else {
        return false;
    }
}
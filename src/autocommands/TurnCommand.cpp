#include "TurnCommand.h"

TurnCommand::TurnCommand(int degrees)
    :
    angle(degrees)
{
    angleOut = &(Hardware::angleOut);
    distOut = &(Hardware::distOut);
    distanceController = &(Hardware::distanceController);
    angleController = &(Hardware::angleController);
    Hardware::changeAngle(angle);
    Hardware::updateControllerPoints();
}

void TurnCommand::init()
{
    distanceController->Enable();
    angleController->Enable();
}

void TurnCommand::step()
{
    double a = Hardware::gyroscope.GetAngle();
    va = a-lastangle;
    lastangle = a;
    double cvelocity = distOut->getOut();
    double cangle = angleOut->getOut();
    Hardware::drivetrain.driveLR(cvelocity+cangle, cvelocity-cangle);
}

bool TurnCommand::finished()
{
    // Check if controllers are on target and robot is sufficiently stationary
    if (std::fabs(Hardware::dist.GetRate()) < Reference::kVd && std::fabs(distanceController->GetError()) < Reference::kEd
    && std::fabs(va) < Reference::kVa && std::fabs(angleController->GetError()) < Reference::kEa) {
        distanceController->Disable();
        angleController->Disable();
        return true;
    }
    else {
        return false;
    }
}
#pragma once
#include "team1538/include/team1538/CowGyro.h"
#include <WPILib.h>

//! Class to manage the PIDOutput interface with an IterativeRobot.

/*
* This class essentially serves as a "collector", collecting the value that it is passed by the PIDController.
* It stores the value so that it may be accessed by other functions such as AutonomousPeriodic.
*/
class ManualPIDOut : public frc::PIDOutput
{
    private:
        double lastOut = 0;
    public:
        double getOut() const {return lastOut;}
        void PIDWrite(double output) {lastOut = output;}
        ManualPIDOut() {}

};

class CowGyroPID : public frc::PIDSource
{
    private:
        team1538::CowGyro *gyro;
     protected:
        frc::PIDSourceType m_pidSource = frc::PIDSourceType::kDisplacement;
    public:
        PIDSourceType GetPIDSourceType() const {return m_pidSource;}
        void SetPIDSourceType(frc::PIDSourceType pidSource) {m_pidSource=pidSource;}
        double PIDGet()
        {
            if (m_pidSource == frc::PIDSourceType::kDisplacement) {
                return gyro->GetAngle();
            }
            else
            {
                return 0;
            }
        }
        CowGyroPID(team1538::CowGyro* g)
        {
            gyro=g;
        }
};
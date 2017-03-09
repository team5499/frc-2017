#pragma once
#include "CowLib/CowGyro.h"
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

/*
* This class implements PID.
*/
class TwoEncoders : public frc::PIDSource
{
    private:
        // Pointers to encoders owned by other classes
        frc::Encoder *l;
        frc::Encoder *r;
    protected:
        frc::PIDSourceType m_pidSource = frc::PIDSourceType::kDisplacement;
    public:
        //! Get our source.
        PIDSourceType GetPIDSourceType() const {return m_pidSource;}
        //! Set the specified sourcetype for both of our encoders.
        void SetPIDSourceType(frc::PIDSourceType pidSource) {l->SetPIDSourceType(pidSource);
                                                             r->SetPIDSourceType(pidSource);
                                                             m_pidSource = pidSource;}
        //! Reset the values for both encoders.
        void Reset() {l->Reset(); r->Reset();}
        //! Return the average of both encoder values.
        double PIDGet() {return (l->PIDGet()+r->PIDGet())/2.0;}
        //! Return velocity
        double GetRate() {return (l->GetRate()+r->GetRate())/2.0;}
        //! Initialize both of our pointers to actual Encoder classes.
        TwoEncoders(frc::Encoder* left, frc::Encoder* right) {l = left; r = right;}

};

class CowGyroPID : public frc::PIDSource
{
    private:
        CowLib::CowGyro *gyro;
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
        CowGyroPID(CowLib::CowGyro* g)
        {
            gyro=g;
        }
};
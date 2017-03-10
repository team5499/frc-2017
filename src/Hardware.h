#pragma once
#include <WPILib.h>
#include "Reference.h"
#include "ManualPID.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Climber.h"
#include "CowLib/CowGyro.h"
class Hardware
{
    private:
        static double perfectAngle;
        static int perfectDistance;
    public:
        static Drivetrain drivetrain;
        static Climber climber;

        // Sensors
        static CowLib::CowGyro gyroscope;
        static frc::Encoder lEncoder;
        static frc::Encoder rEncoder;
        static TwoEncoders dist;

        // PIDControllers
        static frc::PIDController distanceController;
        static frc::PIDController angleController;
        static ManualPIDOut angleOut;
        static ManualPIDOut distOut;
        static CowGyroPID pidgyro;

        static inline void changeAngle(double dAngle) { perfectAngle+=dAngle; }
        static inline void changeDistance(double dDist) { perfectDistance+=dDist; }
        static inline void updateControllerPoints() {
            distanceController.SetSetpoint(perfectDistance);
            angleController.SetSetpoint(perfectAngle);
        }

};

//Force the hardware to be initialized
static Hardware _init_hardware;
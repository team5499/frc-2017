#pragma once
#include <WPILib.h>
#include "Reference.h"
#include "ManualPID.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Climber.h"
#include "subsystems/Gearmech.h"
#include "team1538/include/team1538/CowGyro.h"
class Hardware
{
    private:
        static double perfectAngle;
        static int perfectDistance;
    public:
        static Drivetrain drivetrain;
        static Climber climber;
        static Gearmech gearmech;

        // Sensors
        static team1538::CowGyro gyroscope;
        static frc::Encoder encoder;

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
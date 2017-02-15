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
        Reference ref;
        double perfectAngle = 0;
        int perfectDistance = 0;
    public:
        Drivetrain drivetrain;
        Climber climber;

        // Sensors
        CowLib::CowGyro gyroscope;
        frc::Encoder lEncoder;
        frc::Encoder rEncoder;
        TwoEncoders dist;

        // PIDControllers
        frc::PIDController distanceController;
        frc::PIDController angleController;
        ManualPIDOut angleOut;
        ManualPIDOut distOut;
        CowGyroPID pidgyro;

        Hardware()
            :
            ref(),
            drivetrain(&ref),
            climber(&ref),
            gyroscope(ref.gyroport),
            lEncoder(ref.lEncoderPortA, ref.lEncoderPortB),
            rEncoder(ref.rEncoderPortA, ref.rEncoderPortB),
            dist(&lEncoder, &rEncoder),
            angleOut(),
            distOut(),
            pidgyro(&gyroscope),
            distanceController(ref.kP, ref.kI, ref.kD, &dist, &distOut),
            angleController(ref.kP, ref.kI, ref.kD, &pidgyro, &angleOut)
        {
            angleController.SetAbsoluteTolerance(ref.kEa);
            angleController.SetToleranceBuffer(ref.toleranceBuffer);
            distanceController.SetAbsoluteTolerance(ref.kEd);
            distanceController.SetToleranceBuffer(ref.toleranceBuffer);
        };

        inline void changeAngle(double dAngle) { perfectAngle+=dAngle; }
        inline void changeDistance(double dDist) { perfectDistance+=dDist; }
        inline void updateControllerPoints() {
            distanceController.SetSetpoint(perfectDistance);
            angleController.SetSetpoint(perfectAngle);
        };

};
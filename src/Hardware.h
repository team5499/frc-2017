#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "Reference.h"
#include "ManualPID.h"
#include "subsystems/Drivetrain.h"


class Hardware
{
    private:
        Reference ref;
    public:
        Drivetrain drivetrain;

        // Sensors
        frc::ADXRS450_Gyro gyroscope;
        frc::Encoder lEncoder;
        frc::Encoder rEncoder;
        TwoEncoders dist;

        // PIDControllers
        frc::PIDController distanceController;
        frc::PIDController angleController;
        ManualPIDOut angleOut;
        ManualPIDOut distOut;

        inline Hardware()
            :
            ref(),
            drivetrain(&ref),
            gyroscope(ref.gyroport),
            lEncoder(ref.lEncoderPortA, ref.lEncoderPortB),
            rEncoder(ref.rEncoderPortA, ref.rEncoderPortB),
            dist(&lEncoder, &rEncoder),
            angleOut(),
            distOut(),
            distanceController(ref.kP, ref.kI, ref.kD, &dist, &distOut),
            angleController(ref.kP, ref.kI, ref.kD, &gyroscope, &angleOut)
        {};

};
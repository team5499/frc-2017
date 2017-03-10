#include "Hardware.h"

double Hardware::perfectAngle = 0;
int Hardware::perfectDistance = 0;

Drivetrain Hardware::drivetrain;
Climber Hardware::climber;
Gearmech Hardware::gearmech;

// Sensors
CowLib::CowGyro Hardware::gyroscope(Reference::gyroport);
frc::Encoder Hardware::lEncoder(Reference::lEncoderPortA, Reference::lEncoderPortB);
frc::Encoder Hardware::rEncoder(Reference::rEncoderPortA, Reference::rEncoderPortB);
ManualPIDOut Hardware::angleOut;
ManualPIDOut Hardware::distOut;
TwoEncoders Hardware::dist(&lEncoder, &rEncoder);

// PIDControllers
frc::PIDController Hardware::distanceController(Reference::kP, Reference::kI, Reference::kD, &dist, &distOut);
frc::PIDController Hardware::angleController(Reference::kP, Reference::kI, Reference::kD, &pidgyro, &angleOut);
CowGyroPID Hardware::pidgyro(&gyroscope);
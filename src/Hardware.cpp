#include "Hardware.h"

double Hardware::perfectAngle = 0;
int Hardware::perfectDistance = 0;

Drivetrain Hardware::drivetrain;
Climber Hardware::climber;
Gearmech Hardware::gearmech;

// Sensors
team1538::CowGyro Hardware::gyroscope;
frc::Encoder Hardware::encoder(Reference::encoderPortA, Reference::encoderPortB);
ManualPIDOut Hardware::angleOut;
ManualPIDOut Hardware::distOut;

// PIDControllers
frc::PIDController Hardware::distanceController(Reference::kP, Reference::kI, Reference::kD, &encoder, &distOut);
frc::PIDController Hardware::angleController(Reference::kP, Reference::kI, Reference::kD, &pidgyro, &angleOut);
CowGyroPID Hardware::pidgyro(&gyroscope);
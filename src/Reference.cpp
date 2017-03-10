#include "Reference.h"

const double Reference::kP = 0.01;
const double Reference::kI = 0.0;
const double Reference::kD = 0.0;

const double Reference::kVd = 10;
const double Reference::kVa = 3;
const double Reference::kEd = 20;
const double Reference::kEa = 1;

const int Reference::toleranceBuffer = 4;

// Joysticks
const int Reference::wheel = 1;
const int Reference::throttle = 0;
const int Reference::xbox = 2;
const double Reference::wheeldeadzone = 0.05;
const double Reference::throttledeadzone = 0.05;
const int Reference::climbbutton = 4;

// Drivetrain Talon Ports
const int Reference::left1id = 0;
const int Reference::left2id = 1;
const int Reference::right1id = 2;
const int Reference::right2id = 3;

// Climber
const int Reference::motorid = 5;

//Gearmech
const int Reference::rollerid = 7;
const int Reference::armid = 6;

// Sensors
const uint32_t Reference::gyroport = 0;
const int Reference::lEncoderPortA = 0;
const int Reference::lEncoderPortB = 1;
const int Reference::rEncoderPortA = 2;
const int Reference::rEncoderPortB = 3;
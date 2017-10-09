#pragma once

#include "../RobotInit.h"
#pragma once

#include "WPILib.h"
#include "../RobotInit.h"
#include "../Reference.h"
#include "DriveTrain.h"
#include "GearMech.h"
#include "Climber.h"
#include "JoySticks.h"

namespace team5499 {

    class subsystems {
    public:
        static GearMech gearMech;
        static DriveTrain driveTrain;
        static Climber climber;
        static JoySticks joysticks;
    };

}
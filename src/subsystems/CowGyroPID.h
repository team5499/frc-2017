#pragma once

#include <iostream>
#include <WPILib.h>
#include <CANTalon.h>
#include <team1538/CowAlphaNum.h>
#include <team1538/CowGyro.h>
#include "../Reference.h"

namespace team5499
{
    class CowGyroPID
    {
    private:
        team1538::CowGyro mxp_gyro;
    public:
        CowGyroPID();
    };
}
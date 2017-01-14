#pragma once
#include <WPILib.h>
#include <CANTalon.h>
#include "Reference.h"

class Hardware
{
    private:
        Reference ref;
    public:
        CANTalon left1;
        CANTalon left2;
        CANTalon right1;
        CANTalon right2;

        inline Hardware()
            :
            ref(),
            left1(ref.left1id),
            left2(ref.left2id),
            right1(ref.right1id),
            right2(ref.right2id) {};

};
#pragma once

#include <iostream>
#include "WPILib.h"
#include "Timer.h"
#include "../subsystems/Subsystems.h"
#include "../Reference.h"

namespace team5499 {
    class GenericAction {
    private:
        double start_time;
        double curr_time;
        double timeout_time;
    public:
        GenericAction() = delete;
        GenericAction(double timeout)
        :
        timeout_time(timeout)
        {
            
        }


        virtual ~GenericAction() {};

        virtual void Handle() = 0;
        virtual void Start() {
            start_time = Timer::GetFPGATimestamp();
            std::cout << start_time;
        }
        virtual bool isFinished() {
            curr_time = Timer::GetFPGATimestamp();
            if(timeout_time <= curr_time) return true;
            return false; 
        }

        virtual void reset() = 0;
    };
}
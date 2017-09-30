#pragma once

#include <WPILib.h>

namespace team5499
{
    class LED
    {
    private:
        double red_value;
        double green_value;
        double blue_value;
        frc::DigitalOutput red_controller;
        frc::DigitalOutput green_controller;
        frc::DigitalOutput blue_controller;

        //flash
        double prev_red;
        double prev_green;
        double prev_blue;
        double start_time;
        int flash_sequence;

        void update_controller(double r, double g, double b);
    public:
        LED();
        void setRGB(double r, double g, double b, bool setVal = true, bool setVar = true);
        void setRed(double r, bool setVal = true, bool setVar = true);
        void setGreen(double g, bool setVal = true, bool setVar = true);
        void setBlue(double b, bool setVal = true, bool setVar = true);
        void handle();
        void flash(double r, double g, double b);
    };
}
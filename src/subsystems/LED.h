#pragma once
#include "../Hardware.h"
#include "../Reference.h"

namespace team5499
{
    class LED
    {
        private:
            frc::DigitalOutput red;
            frc::DigitalOutput green;
            frc::DigitalOutput blue;
        public:
            LED()
                :
                red(Reference::red_port),
                green(Reference::green_port),
                blue(Reference::blue_port)
            {
                red.EnablePWM(0);
                red.SetPWMRate(62.5);

                green.EnablePWM(0);
                green.SetPWMRate(62.5);

                blue.EnablePWM(0);
                blue.SetPWMRate(62.5);
            }

            //intensity is a value between 0 and 255
            void setRed(double intensity)
            {
                red.UpdateDutyCycle(intensity/255);
            }
            void setGreen(double intensity)
            {
                green.UpdateDutyCycle(intensity/255);
            }
            void setBlue(double intensity)
            {
                blue.UpdateDutyCycle(intensity/255);
            }
    };
}
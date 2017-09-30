#include "LED.h"

namespace team5499
{
    LED::LED()
    :
    red_value(0),
    green_value(0),
    blue_value(0),
    red_controller(0),
    green_controller(1),
    blue_controller(2),
    prev_red(0),
    prev_green(0),
    prev_blue(0),
    start_time(0),
    flash_sequence(-1)
    {
        std::cout << "led init" << std::endl;
        red_controller.EnablePWM(0);
        red_controller.SetPWMRate(100);

        green_controller.EnablePWM(0);
        green_controller.SetPWMRate(100);

        blue_controller.EnablePWM(0);
        blue_controller.SetPWMRate(100);
    }
    void LED::update_controller(double r, double g, double b)
    {
        red_controller.UpdateDutyCycle(r/100);
        green_controller.UpdateDutyCycle(g/100);
        blue_controller.UpdateDutyCycle(b/100);
    }

    void LED::setRGB(double r, double g, double b, bool setVal, bool setVar)
    {
        if(setVar)
        {
            red_value = r;
            green_value = g;
            blue_value = b;
        }   

        if(setVal)
            update_controller(r, g, b);
    }
    void LED::setRed(double r, bool setVal, bool setVar)
    {
        setRGB(r, green_value, blue_value, setVal, setVar);
    }
    void LED::setGreen(double g, bool setVal, bool setVar)
    {
        setRGB(red_value, g, blue_value, setVal, setVar);
    }
    void LED::setBlue(double b, bool setVal, bool setVar)
    {
        setRGB(red_value, green_value, b, setVal, setVar);
    }
    void LED::handle()
    {
        if(flash_sequence != -1)
        {
            if(Timer::GetFPGATimestamp() - start_time > 0.25)
            {
                flash_sequence++;
                start_time = Timer::GetFPGATimestamp();
            }

            if(flash_sequence % 2 == 0)
                setRGB(red_value, green_value, blue_value, true, false);
            else
                setRGB(0, 0, 0, true, false);

            if(flash_sequence > 10)
            {
                flash_sequence = -1;
                setRGB(prev_red, prev_green, prev_blue);
            }
        }
    }
    void LED::flash(double r, double g, double b)
    {
        prev_red = red_value;
        prev_green = green_value;
        prev_blue = blue_value;
        setRGB(r, g, b, false);
        flash_sequence = 0;
        start_time = Timer::GetFPGATimestamp();
    }
}
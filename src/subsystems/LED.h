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
    }
    void disable()
    {
      setRed(false);
      setGreen(false);
      setBlue(false);
    }

    //intensity is a value between 0 and 255
    void setRed(bool on)
    {
      //intensity = std::min(std::max(intensity, 0.0), 255.0);
      //red.UpdateDutyCycle(intensity / 255);
      red.Set(on);
    }

    void setGreen(bool on)
    {
      //intensity = std::min(std::max(intensity, 0.0), 255.0);
      //green.UpdateDutyCycle(intensity / 255);
      green.Set(on);
    }

    void setBlue(bool on)
    {
      //intensity = std::min(std::max(intensity, 0.0), 255.0);
      //blue.UpdateDutyCycle(intensity / 255);
      blue.Set(on);
    }

    void setHSV(float h, float s, float v){
    float r, g, b;

    int i = floor(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch(i % 6){
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }

    setRed((double) r);
    setGreen((double) g);
    setBlue((double) b);
}
  };
}
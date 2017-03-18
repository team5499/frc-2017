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

    void setRed(bool on)
    {
      red.Set(on);
    }

    void setGreen(bool on)
    {
      green.Set(on);
    }

    void setBlue(bool on)
    {
      blue.Set(on);
    }
  };
}
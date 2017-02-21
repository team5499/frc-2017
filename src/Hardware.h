#pragma once

#include <WPILib.h>
#include <CANTalon.h>

class Hardware
{
private:
  class Drivetrain {
  public:
    CANTalon left1;
    CANTalon left2;
    CANTalon right1;
    CANTalon right2;

    Drivetrain()
    :
            left1(1),
            left2(2),
            right1(3),
            right2(4)
    {
    }
  };

  class Climber {
  public:
    CANTalon climber;

    Climber()
            :
            climber(5)
    {
    }
  };

  class ControlBoard {
  public:
    frc::Joystick xboxController;

    ControlBoard()
            :
            xboxController(0)
    {
    }
  };

public:
  Drivetrain drivetrain;
  Climber climber;
  ControlBoard controlBoard;

  Hardware()
  :
          drivetrain(),
          climber(),
          controlBoard()
  {
  }
};
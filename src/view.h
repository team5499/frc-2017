#pragma once

#include <range/v3/all.hpp>
#include <WPILib.h>

namespace team5499
{
  namespace view
  {
    auto button(int stick)
    {
      return ranges::view::ints |
             ranges::view::transform(
                     [stick](int button)
                     {
                       return frc::DriverStation::GetInstance().GetStickButton(
                               stick,
                               button);
                     }
             );
    }

    auto axis(int stick)
    {
      return ranges::view::ints |
             ranges::view::transform(
                     [stick](int axis)
                     {
                       return frc::DriverStation::GetInstance().GetStickAxis(
                               stick,
                               axis);
                     }
             );
    }

    auto pov(int stick)
    {
      return ranges::view::ints |
             ranges::view::transform(
                     [stick](int pov)
                     {
                       return frc::DriverStation::GetInstance().GetStickPOV(
                               stick,
                               pov);
                     }
             );
    }

    auto deadband(double band)
    {
      return ranges::view::transform(
              [band](double signal)
              {
                return (fabs(signal) < band) ? 0 : signal;
              }
      );
    }
  }
}
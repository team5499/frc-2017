#pragma once

#include <range/v3/all.hpp>
#include <WPILib.h>

namespace team5499
{
  namespace view
  {
    auto button_view(int stick)
    {
      return ranges::view::ints | ranges::view::transform([stick](int button)
                                                          {
                                                            return frc::DriverStation::GetInstance().GetStickButton(
                                                                    stick,
                                                                    button);
                                                          });
    }

    auto axis_view(int stick)
    {
      return ranges::view::ints | ranges::view::transform([stick](int axis)
                                                          {
                                                            return frc::DriverStation::GetInstance().GetStickAxis(
                                                                    stick,
                                                                    axis);
                                                          });
    }
  }
}
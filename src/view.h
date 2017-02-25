#pragma once

#include <range/v3/all.hpp>
#include <WPILib.h>

namespace team5499
{
  namespace view
  {
    auto button(int stick)
    {
      return ranges::view::ints | ranges::view::transform([stick](int button)
                                                          {
                                                            return frc::DriverStation::GetInstance().GetStickButton(
                                                                    stick,
                                                                    button);
                                                          });
    }

    auto axis(int stick)
    {
      return ranges::view::ints | ranges::view::transform([stick](int axis)
                                                          {
                                                            return frc::DriverStation::GetInstance().GetStickAxis(
                                                                    stick,
                                                                    axis);
                                                          });
    }

    auto falling_edge(auto left_range, auto right_range)
    {
      return ranges::view::zip_with(left_range, right_range, [](int left, int right)
      {
        return right < left;
      });
    }

    auto rising_edge(auto left_range, auto right_range)
    {
      return ranges::view::zip_with(left_range, right_range, [](int left, int right)
      {
        return right > left;
      });
    }
  }
}
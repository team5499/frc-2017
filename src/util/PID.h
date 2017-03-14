#pragma once

namespace team5499
{
  namespace util
  {
    inline auto PID(double P, double I, double D, double F)
    {
      return [P, I, D, F](double sp, double pv)
      {
        static double accumulation = 0;
        static double previous_error = 0;
        static double last_calculation_time = Timer::GetFPGATimestamp();

        // TODO: reset accumulation on sp changed / reached

        double component_P = (sp - pv) * P;
        double component_I = accumulation * I;
        double component_D =
                ((sp - pv) - previous_error) /
                (Timer::GetFPGATimestamp() - last_calculation_time) * D;
        double component_F = sp * F;

        accumulation += (sp - pv);
        previous_error = (sp - pv);
        last_calculation_time = Timer::GetFPGATimestamp();

        return component_P + component_I + component_D + component_F;
      };
    };
  }
}

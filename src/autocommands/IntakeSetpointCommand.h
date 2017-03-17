#pragma

#include "GenericCommand.h"
#include "../subsystems/Subsystems.h"

namespace team5499
{
  class IntakeSetpointCommand : public GenericCommand
  {
  private:
    double m_Setpoint;
  public:
    IntakeSetpointCommand(double timeout, double setpoint)
      :
      GenericCommand(timeout),
      m_Setpoint(setpoint)
    {
    }

    void Step() override
    {
      subsystems::gearmech.SetSetpoint(m_Setpoint);
    }
  };
}
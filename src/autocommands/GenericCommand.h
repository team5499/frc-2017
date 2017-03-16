#pragma once

#include <WPILib.h>

namespace team5499
{
  class GenericCommand
  {
  private:
    double m_StartTime;
    double m_Timeout;
    bool m_Started = false;
    bool m_Finished = false;
  public:
    GenericCommand() = delete;

    GenericCommand(double timeout)
      :
      m_Timeout(timeout)
    {
    }

    virtual ~GenericCommand() {};

    virtual void Start()
    {
      m_StartTime = Timer::GetFPGATimestamp();
      m_Started = true;
    }

    void Reset()
    {
      m_Started = false;
      m_Finished = false;
    }

    virtual void Step() = 0;

    bool IsStarted()
    {
      return m_Started;
    }

    bool IsFinished()
    {
      return m_Finished;
    };

    bool Finished()
    {
      m_Finished = true;
    }

    bool IsTimedOut()
    {
      return Timer::GetFPGATimestamp() > m_StartTime + m_Timeout;
    }
  };
}
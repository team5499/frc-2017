#pragma once

#include "GenericCommand.h"

namespace team5499
{
  template<typename T, typename... Ts>
  class AutoRoutine
  {
  private:
    T m_Command;
    AutoRoutine<Ts...> m_Next;

  public:

    AutoRoutine(T command, Ts... remaining)
      :
      m_Command(command),
      m_Next(remaining...)
    {
    }

    AutoRoutine<Ts...>& Next()
    {
      return m_Next;
    }

    T& Get()
    {
      return m_Command;
    }
  };

  template<typename T>
  class AutoRoutine<T>
  {
  private:
    T m_Command;

  public:
    AutoRoutine(T command)
      :
      m_Command(command)
    {
    }

    T& Get()
    {
      return m_Command;
    }
  };

  template<typename... Ts>
  AutoRoutine<Ts...>&& make_auto_routine(Ts... commands)
  {
    return std::move(AutoRoutine<Ts...>(commands...));
  }
}
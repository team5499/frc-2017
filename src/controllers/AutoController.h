#pragma once

#include <queue>
#include <unordered_map>
#include <string>

#include "GenericController.h"
#include "../autocommands/AutoRoutine.h"
#include "../autocommands/GenericCommand.h"
#include "../autocommands/DoNothingCommand.h"

namespace team5499
{
  template<typename... Ts>
  class AutoController : public GenericController
  {
  private:
    std::tuple<Ts...> m_Routines;

  public:
    AutoController(Ts... routines)
      :
      m_Routines(std::make_tuple(routines...))
    {
    }

    void Step() override;
    template<typename U, typename... Us>
    void Step(AutoRoutine<U, Us...>&  currentRoutine);
    template<typename U>
    void Step(AutoRoutine<U>& currentRoutine);

    void Reset();
    template<typename U, typename... Us>
    void Reset(AutoRoutine<U, Us...>&  currentRoutine);
    template<typename U>
    void Reset(AutoRoutine<U>& currentRoutine);
  };

  template<typename... Ts>
  void AutoController<Ts...>::Step()
  {
    Step(std::get<0>(m_Routines));
  }

  template<typename... Ts>
  template<typename U, typename... Us>
  void AutoController<Ts...>::Step(AutoRoutine<U, Us...>& currentRoutine)
  {
    U& currentCommand = currentRoutine.Get();

    if(!currentCommand.IsStarted())
    {
      currentCommand.Start();
    }

    if(currentCommand.IsFinished() || currentCommand.IsTimedOut())
    {
      Step(currentRoutine.Next());
      return;
    }

    currentCommand.Step();
  }

  template<typename... Ts>
  template<typename U>
  void AutoController<Ts...>::Step(AutoRoutine<U>& currentRoutine)
  {
    U& currentCommand = currentRoutine.Get();

    if(!currentCommand.IsStarted())
    {
      currentCommand.Start();
    }

    if(currentCommand.IsFinished() || currentCommand.IsTimedOut())
    {
      return;
    }

    currentCommand.Step();
  }

  template<typename... Ts>
  void AutoController<Ts...>::Reset()
  {
    Reset(std::get<0>(m_Routines));
  }

  template<typename... Ts>
  template<typename U, typename... Us>
  void AutoController<Ts...>::Reset(AutoRoutine<U, Us...>& currentRoutine)
  {
    U& currentCommand = currentRoutine.Get();
    currentCommand.Reset();
    Reset(currentRoutine.Next());
  }

  template<typename... Ts>
  template<typename U>
  void AutoController<Ts...>::Reset(AutoRoutine<U>& currentRoutine)
  {
    U& currentCommand = currentRoutine.Get();
    currentCommand.Reset();
  }

  template<typename... Ts>
  AutoController<Ts...> make_auto_controller(Ts... commands)
  {
    return AutoController<Ts...>(commands...);
  }
}
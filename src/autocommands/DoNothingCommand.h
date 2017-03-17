#pragma once

#include "GenericCommand.h"

namespace team5499
{
  class DoNothingCommand : public GenericCommand
  {
  public:
    DoNothingCommand(double timeout)
      :
      GenericCommand(timeout)
    {
    }

    void Step() override {}
  };
}
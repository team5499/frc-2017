#pragma once

namespace team5499
{
  class GenericAutoCommand
  {
  public:
    virtual ~GenericAutoCommand() {};
    virtual void Handle() = 0;
    virtual void Init() = 0;
    virtual void isFinished() = 0;
  };
}
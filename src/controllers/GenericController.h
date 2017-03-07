#pragma once

namespace team5499
{
  class GenericController
  {
  private:

  public:
    virtual ~GenericController() {};
    virtual void handle() = 0;
    virtual void start() = 0;
  };
}
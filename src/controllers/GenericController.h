#pragma once

namespace team5499
{
  class GenericController
  {
  public:
    virtual ~GenericController() {};
    virtual void Step() = 0;
  };
}
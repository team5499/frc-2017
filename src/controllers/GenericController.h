#pragma once

namespace team5499
{
  class GenericController
  {
  public:
    virtual ~GenericController() {};
    virtual void Start() = 0;
    virtual void Handle() = 0;
  };
}
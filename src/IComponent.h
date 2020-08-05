#pragma once

class IComponent {
  public:
    virtual void setup(){};
    virtual void update(){};
    virtual ~IComponent(){};
};

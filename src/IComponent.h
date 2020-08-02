// This is needed so that we avoid redefinition errors
#pragma once

class IComponent {
  public:
    virtual void setup(){};
    virtual void update(){};
    virtual ~IComponent(){};
};

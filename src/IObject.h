// This is needed so that we avoid redefinition errors
#pragma once

class IObject {
  public:
    virtual void setup(){};
    virtual void update(){};
    virtual ~IObject(){};
};

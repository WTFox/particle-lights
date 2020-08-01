// This is needed so that we avoid redefinition errors
#pragma once

class IArduinoObject {
  public:
    virtual void setup(){};
    virtual void update(){};
    virtual ~IArduinoObject(){};
};

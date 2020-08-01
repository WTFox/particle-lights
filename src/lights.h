#pragma once

#include "arr.h"

class Lights : public IArduinoObject {
  public:
    Lights(){};
    int iteration;
    void setup() override;
    void update() override;
};

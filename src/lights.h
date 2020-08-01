#pragma once

#include "IObject.h"

class Lights : public IObject {
  public:
    int iteration;
    void setup() override;
    void update() override;
};

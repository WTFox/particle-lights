#pragma once

#include "IObject.h"

class Lights : public IObject {
    int iteration_ = 0;
    int brightness_ = 100;
    bool onCall_ = false;

  public:
    void setup() override;
    void update() override;

    int getBrightness();
    void setBrightness(int value);

    bool getOnCall();
    void setOnCall(bool value);
};

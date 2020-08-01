#pragma once

#include "IObject.h"
#include "neopixel.h"

class Lights : public IObject {
    int iteration_ = 0;
    int brightness_ = 100;
    bool onCall_ = false;
    Adafruit_NeoPixel *strip_;

  public:
    void setup() override;
    void update() override;

    int getBrightness();
    void setBrightness(int value);

    bool getOnCall();
    void setOnCall(bool value);
};

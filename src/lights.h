#pragma once

#include "IComponent.h"
#include "neopixel.h"

class Lights : public IComponent {
    uint8_t iteration_ = 0;
    uint8_t brightness_ = 100;
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

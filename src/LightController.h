#pragma once

#include "IComponent.h"
#include "neopixel.h"

class LightController : public IComponent {
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

uint32_t Wheel(byte WheelPos);
void colorAll(Adafruit_NeoPixel *strip, uint32_t c, uint8_t wait);
void rainbowFromIteration(Adafruit_NeoPixel *strip, uint8_t iteration);

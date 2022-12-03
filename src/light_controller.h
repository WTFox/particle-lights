#pragma once

#include "component.h"
#include "neopixel.h"

class LightController : public IComponent {
    uint8_t iteration_ = 0;
    uint8_t brightness_ = 200;
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

uint32_t wheel(byte WheelPos);
void colorAll(Adafruit_NeoPixel *strip, uint32_t c);
void rainbow(Adafruit_NeoPixel *strip, uint8_t iteration);

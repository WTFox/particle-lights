#include "neopixel.h"

uint32_t Wheel(byte WheelPos);

void rainbow(Adafruit_NeoPixel *strip, uint8_t wait);
void colorAll(Adafruit_NeoPixel *strip, uint32_t c, uint8_t wait);
void RainbowStepper(Adafruit_NeoPixel *strip, uint8_t iteration);

#include "neopixel.h"

SYSTEM_MODE(AUTOMATIC);

#define PIXEL_PIN D5
#define PIXEL_COUNT 99
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int brightness = 100;
bool onCall = false;

void setup() {
  strip.begin();
  strip.show();

  Particle.variable("brightness", brightness);
  Particle.variable("onCall", onCall);

  Particle.function("setBrightness", setBrightness);
  Particle.function("toggleOnCall", toggleOnCall);
}

void loop() {
  strip.setBrightness(brightness);
  if (onCall) {
    strip.setBrightness(200);
    colorAll(strip.Color(255, 0, 100), 20);
  } else {
    rainbow(20);
  }
}

int setBrightness(String input) {
  brightness = input.toInt();
  return 0;
}

int toggleOnCall(String input) {
  onCall = !onCall;
  return 0;
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void colorAll(uint32_t c, uint8_t wait) {
  uint16_t i;

  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

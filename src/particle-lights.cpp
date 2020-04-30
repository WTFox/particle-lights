/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/anthonyfox/dev/particle-lights/src/particle-lights.ino"
#include "neopixel.h"

void setup();
void loop();
int setBrightness(String input);
int notifyOnCall(String input);
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);
#line 3 "/Users/anthonyfox/dev/particle-lights/src/particle-lights.ino"
SYSTEM_MODE(AUTOMATIC);

#define PIXEL_PIN D5
#define PIXEL_COUNT 99
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int defaultRoutine(String input);

int brightness = 100;

void setup() {
  strip.begin();
  strip.show();

  Particle.variable("brightness", brightness);

  Particle.function("setBrightness", setBrightness);
  Particle.function("notifyOnCall", notifyOnCall);
  Particle.function("defaultRoutine", defaultRoutine);
}

void loop() {
  strip.setBrightness(brightness);
  defaultRoutine("");
}

int setBrightness(String input) {
  brightness = input.toInt();
  return 0;
}

int defaultRoutine(String input) {
  rainbow(20);
  return 0;
}

int notifyOnCall(String input) {
  uint16_t i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, RGB_COLOR_MAGENTA);
  }
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

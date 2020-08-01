#include "lights.h"
#include "neopixel.h"
#include "patterns.h"

// #define PIXEL_PIN D5
// #define PIXEL_COUNT 99
// #define PIXEL_TYPE WS2811

// Adafruit_NeoPixel *strip =
//     new Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// int brightness = 100;
// bool onCall = false;

void Lights::setup() {
    Serial.println("Lights::setup");
    // strip->begin();
    // strip->show();
    // Particle.variable("brightness", brightness);
    // Particle.variable("onCall", onCall);
    // Particle.function("setBrightness", setBrightness);
    // Particle.function("toggleOnCall", toggleOnCall);
}

void Lights::update() {
    Serial.println("Lights::update");
    // strip->setBrightness(255);
    // for (uint16_t i = 0; i < strip->numPixels(); i++) {
    //     strip->setPixelColor(i, Adafruit_NeoPixel::Color(255, 0, 100));
    // }
    // strip->show();
    // delay(20);
    // if (onCall) {
    //     strip->setBrightness(200);
    //     colorAll(strip, Adafruit_NeoPixel::Color(255, 0, 100), 20);
    // } else {
    //     rainbow(strip, 20);
    // }
}

// int setBrightness(String input) {
//     brightness = input.toInt();
//     return 0;
// }

// int toggleOnCall(String input) {
//     onCall = !onCall;
//     return 0;
// }

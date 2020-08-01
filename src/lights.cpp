#include "lights.h"
#include "neopixel.h"
#include "patterns.h"

#define PIXEL_PIN D5
#define PIXEL_COUNT 99
#define PIXEL_TYPE WS2811

void Lights::setup() {
    strip_ = new Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
    strip_->begin();
    strip_->show();
}

void Lights::update() {
    strip_->setBrightness(brightness_);

    if (onCall_) {
        strip_->setBrightness(200);
        colorAll(strip_, Adafruit_NeoPixel::Color(255, 0, 100), 20);
    } else {
        rainbowFromIteration(strip_, iteration_);
    }

    // Resetting iteration_ to 0 once we hit 257 so that we can correctly cycle
    // through 256 colors.
    iteration_++;
    if (iteration_ >= 256) {
        iteration_ = 0;
    }
    delay(20);
}

int Lights::getBrightness() { return brightness_; }
void Lights::setBrightness(int value) { brightness_ = value; }

bool Lights::getOnCall() { return onCall_; }
void Lights::setOnCall(bool value) { onCall_ = value; }

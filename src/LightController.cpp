#include "LightController.h"
#include "neopixel.h"
#include "patterns.h"

#define PIXEL_PIN D5
#define PIXEL_COUNT 99
#define PIXEL_TYPE WS2811

void LightController::setup() {
    strip_ = new Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
    strip_->begin();
    strip_->show();
}

void LightController::update() {
    strip_->setBrightness(brightness_);

    if (onCall_) {
        strip_->setBrightness(200);
        colorAll(strip_, strip_->Color(255, 0, 100), 20);
    } else {
        rainbowFromIteration(strip_, iteration_);
    }

    iteration_++;
    delay(20);
}

int LightController::getBrightness() { return brightness_; }
void LightController::setBrightness(int value) { brightness_ = value; }

bool LightController::getOnCall() { return onCall_; }
void LightController::setOnCall(bool value) { onCall_ = value; }

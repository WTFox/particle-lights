#include "LightController.h"
#include "neopixel.h"
#include "patterns.h"

#define PIXEL_PIN D5
#define PIXEL_COUNT 99
#define PIXEL_TYPE WS2811

void LightController::setup() {
    this->strip_ = new Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
    this->strip_->begin();
    this->strip_->show();
}

void LightController::update() {
    this->strip_->setBrightness(this->brightness_);

    if (this->onCall_) {
        this->strip_->setBrightness(200);
        colorAll(this->strip_, Adafruit_NeoPixel::Color(255, 0, 100), 20);
    } else {
        rainbowFromIteration(this->strip_, this->iteration_);
    }

    // this->iteration_ will increment to 255 before resetting to 0. This is
    // intentional as it allows us to effectively iterate over 255 different
    // shades of each color before restarting the color wheel cycle.
    this->iteration_++;
    delay(20);
}

int LightController::getBrightness() { return this->brightness_; }
void LightController::setBrightness(int value) { this->brightness_ = value; }

bool LightController::getOnCall() { return this->onCall_; }
void LightController::setOnCall(bool value) { this->onCall_ = value; }

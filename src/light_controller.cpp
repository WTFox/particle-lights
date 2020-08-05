#include "light_controller.h"
#include "neopixel.h"

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
        colorAll(this->strip_, Adafruit_NeoPixel::Color(255, 0, 100));
    } else {
        rainbow(this->strip_, this->iteration_);
    }

    // this->iteration_ will increment to 255 before resetting to 0. This is
    // intentional as it allows us to effectively iterate over 255 different
    // shades of each color before restarting the color wheel cycle.
    this->iteration_++;
}

int LightController::getBrightness() { return this->brightness_; }
void LightController::setBrightness(int value) { this->brightness_ = value; }

bool LightController::getOnCall() { return this->onCall_; }
void LightController::setOnCall(bool value) { this->onCall_ = value; }

// --- Pattern functions ---

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t wheel(byte WheelPos) {
    if (WheelPos < 85) {
        return Adafruit_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return Adafruit_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
        WheelPos -= 170;
        return Adafruit_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
}

void colorAll(Adafruit_NeoPixel *strip, uint32_t c) {
    for (uint16_t i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, c);
    }
    strip->show();
    delay(20);
}

void rainbow(Adafruit_NeoPixel *strip, uint8_t iteration) {
    for (uint8_t i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, wheel((i + iteration) & 255));
    }
    strip->show();
    delay(20);
}

#include "IObject.h"
#include "lights.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

std::vector<IObject *> objects;

Lights *lights = new Lights();

int toggleOnCall(String input) {
    lights->setOnCall(!lights->getOnCall());
    return 0;
}

int getOnCall(String input) { return lights->getOnCall(); }

int setBrightness(String input) {
    lights->setBrightness(input.toInt());
    return 0;
}

int getBrightness(String input) { return lights->getBrightness(); }

void setup() {
    objects.push_back(lights);

    // Run setup for all objects
    for (uint i = 0; i < objects.size(); i++) {
        objects[i]->setup();
    }

    // Particle stuff
    Particle.function("getBrightness", getBrightness);
    Particle.function("setBrightness", setBrightness);
    Particle.function("toggleOnCall", toggleOnCall);
    Particle.function("getOnCall", getOnCall);
}

void loop() {
    // run update for all objects
    for (uint i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
}

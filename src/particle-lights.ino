#include "IObject.h"
#include "lights.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

// A reference to a Lights object
Lights *lights;

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

void registerParticleFunctions() {
    Particle.function("getBrightness", getBrightness);
    Particle.function("setBrightness", setBrightness);
    Particle.function("toggleOnCall", toggleOnCall);
    Particle.function("getOnCall", getOnCall);
}

// objects hold a collection of IObject's. These ensure that the methods setup()
// and update() exist.
std::vector<IObject *> objects;

void setup() {
    registerParticleFunctions();

    lights = new Lights();
    objects.push_back(lights);

    // Run setup for all objects
    for (uint i = 0; i < objects.size(); i++) {
        objects[i]->setup();
    }
}

void loop() {
    // run update for all objects
    for (uint i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
}

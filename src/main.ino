#include "IComponent.h"
#include "LightController.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

// A reference to a LightController component
LightController *lightController;

int toggleOnCall(String input) {
    lightController->setOnCall(!lightController->getOnCall());
    return 0;
}

int getOnCall(String input) { return lightController->getOnCall(); }

int setBrightness(String input) {
    lightController->setBrightness(input.toInt());
    return 0;
}

int getBrightness(String input) { return lightController->getBrightness(); }

void registerParticleFunctions() {
    Particle.function("getBrightness", getBrightness);
    Particle.function("setBrightness", setBrightness);
    Particle.function("toggleOnCall", toggleOnCall);
    Particle.function("getOnCall", getOnCall);
}

// components hold a collection of IComponent's. These ensure that the methods
// setup() and update() exist.
std::vector<IComponent *> components;

void setup() {
    registerParticleFunctions();

    lightController = new LightController();
    components.push_back(lightController);

    // Run setup for all components
    for (uint i = 0; i < components.size(); i++) {
        components[i]->setup();
    }
}

void loop() {
    // run update for all components
    for (uint i = 0; i < components.size(); i++) {
        components[i]->update();
    }
}

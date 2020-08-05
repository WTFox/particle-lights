#include "IComponent.h"
#include "LightController.h"
#include <vector>

LightController *lightController;

std::vector<IComponent *> components;

void setup() {
    registerParticleFunctions();

    lightController = new LightController();
    components.push_back(lightController);

    for (IComponent *component : components) {
        component->setup();
    }
}

void loop() {
    for (IComponent *component : components) {
        component->update();
    }
}

// Particle Functions/Variables
void registerParticleFunctions() {
    Particle.function("getBrightness", getBrightness);
    Particle.function("setBrightness", setBrightness);
    Particle.function("toggleOnCall", toggleOnCall);
    Particle.function("getOnCall", getOnCall);
}

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

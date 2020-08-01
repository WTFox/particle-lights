#include "IObject.h"
#include "lights.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

std::vector<IObject *> objects;

void setup() {
    Lights *lights = new Lights();
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

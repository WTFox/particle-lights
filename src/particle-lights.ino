#include "arr.h"
#include "lights.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

std::vector<IArduinoObject> objects;

void setup() {
    Lights lights;
    objects.push_back(lights);

    for (uint i = 0; i < objects.size(); i++) {
        objects[i].setup();
    }
}

void loop() {
    for (uint i = 0; i < objects.size(); i++) {
        objects[i].update();
    }
}

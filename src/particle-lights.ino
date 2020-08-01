#include "arr.h"
#include "lights.h"
#include <vector>

SYSTEM_MODE(AUTOMATIC);

std::vector<Lights *> objects;

void setup() {
    Serial.begin(9600);

    Lights *lights = new Lights();
    objects.push_back(lights);

    Serial.println(objects.size());

    for (uint i = 0; i < objects.size(); i++) {
        objects[i]->setup();
    }
}

void loop() {
    for (uint i = 0; i < objects.size(); i++) {
        Serial.println("main loop");
        // Serial.println(typeid(objects[i]).name());
        objects[i]->update();
    }
    delay(5000);
}

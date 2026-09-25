#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

void setup() {
    Serial.begin(115200);
}

void loop() {
    int rawValue = analogRead(LIGHT_SENSOR_PIN);
    Serial.print("raw=");
    Serial.println(rawValue);
    delay(500);
}

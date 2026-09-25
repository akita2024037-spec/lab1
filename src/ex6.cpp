#include "Arduino.h"

#define BLUE_LED_PIN 14

void setup() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    digitalWrite(BLUE_LED_PIN, LOW);

    Serial.begin(115200);
}

void loop() {
    if (Serial.available() > 0) {
        char received = Serial.read();

        if (received == 'B') {
            digitalWrite(BLUE_LED_PIN, HIGH);
            Serial.println("BLUE=1");
        } else if (received == 'b') {
            digitalWrite(BLUE_LED_PIN, LOW);
            Serial.println("BLUE=0");
        }
    }
}

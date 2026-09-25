


#include "Arduino.h"

#define RED_LED_PIN 26

bool redState = false;

void setup() {
    pinMode(RED_LED_PIN, OUTPUT);
    digitalWrite(RED_LED_PIN, LOW);

    Serial.begin(115200);
}

void loop() {
    redState = !redState;
    digitalWrite(RED_LED_PIN, redState ? HIGH : LOW);
    Serial.println(redState ? "RED ON" : "RED OFF");
    delay(500);
}

#include "Arduino.h"

#define BUTTON_PIN 25
#define YELLOW_LED_PIN 12
#define LIGHT_SENSOR_PIN 33

bool lastButtonState = false;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);

    Serial.begin(115200);
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH && !lastButtonState) {
        int snapshot = analogRead(LIGHT_SENSOR_PIN);
        Serial.print("snapshot=");
        Serial.println(snapshot);

        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }

    lastButtonState = buttonState;
    delay(20);
}

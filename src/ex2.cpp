#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN 25

bool greenState = false;
bool lastButtonState = false;

void setup() {
    pinMode(GREEN_LED_PIN, OUTPUT);
    digitalWrite(GREEN_LED_PIN, LOW);

    pinMode(BUTTON_PIN, INPUT);

    Serial.begin(115200);
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH && !lastButtonState) {
        greenState = !greenState;
        digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
        Serial.println(greenState ? "GREEN=1" : "GREEN=0");
    }

    lastButtonState = buttonState;
    delay(20);
}

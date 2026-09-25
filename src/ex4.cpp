#include "Arduino.h"

#define BLUE_LED_PIN 14
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define RED_LED_PIN 26
#define LIGHT_SENSOR_PIN 33

void setLedState(int pin, bool on) {
    digitalWrite(pin, on ? HIGH : LOW);
}

void setOnlyOneLed(const char* band) {
    setLedState(BLUE_LED_PIN, false);
    setLedState(GREEN_LED_PIN, false);
    setLedState(YELLOW_LED_PIN, false);
    setLedState(RED_LED_PIN, false);

    if (strcmp(band, "BLUE") == 0) {
        setLedState(BLUE_LED_PIN, true);
    } else if (strcmp(band, "GREEN") == 0) {
        setLedState(GREEN_LED_PIN, true);
    } else if (strcmp(band, "YELLOW") == 0) {
        setLedState(YELLOW_LED_PIN, true);
    } else if (strcmp(band, "RED") == 0) {
        setLedState(RED_LED_PIN, true);
    }
}

void setup() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    Serial.begin(115200);
}

void loop() {
    int lightValue = analogRead(LIGHT_SENSOR_PIN);
    const char* band = "RED";

    if (lightValue <= 1023) {
        band = "BLUE";
    } else if (lightValue <= 2047) {
        band = "GREEN";
    } else if (lightValue <= 3071) {
        band = "YELLOW";
    } else {
        band = "RED";
    }

    setOnlyOneLed(band);
    Serial.print("band=");
    Serial.println(band);
    delay(250);
}

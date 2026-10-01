#include <Arduino.h>

#define LED_PIN 2 

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Светодиод: ВКЛ");
    delay(1000);
    
    digitalWrite(LED_PIN, LOW);
    Serial.println("Светодиод: ВЫКЛ");
    delay(1000);
}
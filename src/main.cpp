#include <Arduino.h>

#define PIN_AIN1 19
#define PIN_AIN2 18
#define PIN_PWMA 21
#define PIN_SWITCH 15

const int pwmFreq = 5000;
const int pwmChannel = 0;
const int pwmResolution = 8;

void setup() {
    Serial.begin(115200);
    pinMode(PIN_AIN1, OUTPUT);
    pinMode(PIN_AIN2, OUTPUT);

    // Включение встроенной подтяжки к питанию для тумблера
    pinMode(PIN_SWITCH, INPUT_PULLUP); 

    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(PIN_PWMA, pwmChannel);
}

void moveMotor(int speed) {
    if (speed > 0) {
        digitalWrite(PIN_AIN1, HIGH);
        digitalWrite(PIN_AIN2, LOW);
        ledcWrite(pwmChannel, speed);
    } else if (speed < 0) {
        digitalWrite(PIN_AIN1, LOW);
        digitalWrite(PIN_AIN2, HIGH);
        ledcWrite(pwmChannel, abs(speed));
    } else {
        digitalWrite(PIN_AIN1, LOW);
        digitalWrite(PIN_AIN2, LOW);
        ledcWrite(pwmChannel, 0);
    }
}

void loop() {
    // Проверка состояния тумблера
    if (digitalRead(PIN_SWITCH) == LOW) {
        // Если тумблер включен — запускается вращение мотора
        Serial.println("Тумблер ВКЛ: Мотор работает");
        moveMotor(200);
    } else {
        // Если тумблер выключен — полностью останавливается мотор
        Serial.println("Тумблер ВЫКЛ: Мотор остановлен");
        moveMotor(0);
    }
    delay(100);
}

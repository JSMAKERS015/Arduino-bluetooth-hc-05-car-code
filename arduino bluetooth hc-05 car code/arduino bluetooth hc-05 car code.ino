#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FLAME_SENSOR_PIN 2
#define BUZZER_PIN 8

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address to 0x27 or 0x3F depending on your I2C module

void setup() {
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Flame Sensor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int flameState = digitalRead(FLAME_SENSOR_PIN);

  if (flameState == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Flame Detected!");
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("No Flame        ");
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500); // Check every 500ms
}

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {

  Serial.begin(9600);
  lcd.begin(20,4);
  
  for(int i = 0; i < 3; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
}
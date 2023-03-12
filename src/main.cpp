#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(){
 
}

void loop()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Test Text");
  lcd.setCursor(2, 1);
  lcd.print("Test Text Line 2");
}
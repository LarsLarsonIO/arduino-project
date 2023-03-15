#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 20, 4);

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop()
{
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    lcd.setCursor(0, 0);
    lcd.print("> Failed to read from DHT Sensor <");
    lcd.clear();
    return;
  }

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" % ");
  lcd.setCursor(0, 2);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
}
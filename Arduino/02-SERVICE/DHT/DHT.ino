#include <DHT.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 4, 5, 2);

DHT dht11 ;

#define DHT11_PIN 7
int hotair= 8 ;

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
   if(DHT.temperature < 30)
  {
    digitalWrite(hotair,HIGH);
  }
  else{
    digitalWrite(hotair,LOW);
  }
  delay(1500);
}

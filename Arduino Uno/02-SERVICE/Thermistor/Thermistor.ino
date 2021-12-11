                                                                //LCD Library
#include <LiquidCrystal.h>
/*
  LCD circuit:
 * LCD RS pin to digital pin 13
 * LCD Enable pin to digital pin 12
 * LCD D4 pin to digital pin 11
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 9
 * LCD D7 pin to digital pin 8
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground

*/
  
                                                                //Thermistor Libraries
#include <OneWire.h>
#include <DallasTemperature.h>
/*
 Thermistor Circuit :
 * Black Ground 
 * Red Vcc
 * Data pin 7 
 * Resistor 550 ohms connects Vcc and Data pin 
*/
                                                                //Thermistor intialization
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

 float Skin_Temp=0;
 
 
                                                                //LCD intialization
const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
                                                                //A variable to Change mode
String T_Mode;

void setup() {
  
  Serial.begin(9600);
  sensors.begin();
                                                                // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

}

void loop() {
  if(Serial.available()){
    T_Mode = Serial.readString();
    Serial.println("Mode_Changed");
    }
 sensors.requestTemperatures();                                 //Skin thermistor
  Skin_Temp=sensors.getTempCByIndex(0);
  
  if (Skin_Temp >27)
  {                                                             //HIGH Skin temp Warning
  Serial.print("Skin_T = ");
  Serial.print(Skin_Temp);
  Serial.println("C ");
  lcd.setCursor(0, 0);
  lcd.print("Warning! HIGH_T");
  lcd.setCursor(0, 1);
  lcd.print("Skin_T = ");
  lcd.print(Skin_Temp);
  lcd.print("C ");
  delay(2000);
  lcd.clear();
  }
  else if (Skin_Temp <20)
  {                                                            //LOW Skin temp Warning
  Serial.print("Skin_T = ");
  Serial.print(Skin_Temp);
  Serial.println("C ");
  lcd.setCursor(0, 0);
  lcd.print("Warning! LOW_T");
  lcd.setCursor(0, 1);
  lcd.print("Skin_T = ");
  lcd.print(Skin_Temp);
  lcd.print("C ");   
  delay(2000);
  lcd.clear(); 
  }  
  else{                                                         //Normal
  Serial.print("Skin_T = ");
  Serial.print(Skin_Temp);
  Serial.println("C ");
  lcd.setCursor(0, 0);
  lcd.print("Skin_T = ");
  lcd.print(Skin_Temp);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  delay(500);
  }
  

  }

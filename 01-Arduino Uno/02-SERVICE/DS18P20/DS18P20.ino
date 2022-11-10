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
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 float Temp=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 sensors.requestTemperatures();                                 //Skin thermistor
  Temp=sensors.getTempCByIndex(0);
      Serial.println(Temp);
}

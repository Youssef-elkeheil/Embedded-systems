#include <LiquidCrystal.h>                                           //LCD Library
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
 * Yellow Data pin 7 
 * Resistor 550 ohms connects Vcc and Data pin 
*/
#include <dht11.h>                                                   //DHT Libraries
/*
 DHT Circuit :
 * Vcc
 * Ground
 * Data pin 6
 */
#define DHT11PIN 6                                                   //DHT PIN 6
dht11 DHT11;


#define ONE_WIRE_BUS 7                                               //Thermistor PIN 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float Skin_Temp=0;

const int RS = 8, EN = 9, D4 = 10, D5 = 11, D6 = 12, D7 = 13;         //LCD PINS(8->13)
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

                                                              
char T_Mode;                                                          //Variables to Change mode
bool S_Mode;
int Heater = 5;                                                       //Heater PIN 5
bool Heater_ON;
bool Warning;                                                         //check if its normal or there is an issue
int R_LED = 4;                                                        //Red LED PIN 4 for Heat warnings
int B_LED = 3;                                                        //Blue LED PIN 3 for humedity warnings
int Y_LED = 2;                                                        //Yellow LED PIN 2 for for Heater disconnection warning
#define Current  A0                                                   //Current sensor PIN A0
int mVperAmp = 200;
float Voltage = 0;
float VRMS = 0;
float AmpsRMS = 0;
float getVPP()                                                      //Function to get Peak to Peak Voltage Value
{
float result;
int readValue;                                                        //value read from the sensor
int maxValue = 0;                                                     // store max value here
int minValue = 1024;                                                  // store min value here

uint32_t start_time = millis();
while((millis()-start_time) < 500)                                    //sample for 0.5 Sec
{
readValue = analogRead(Current);
// see if you have a new maxValue
if (readValue > maxValue)
{
                                                                      //record the maximum sensor value
maxValue = readValue;
}
if (readValue < minValue)
{
                                                                      //record the minimum sensor value
minValue = readValue;
}
}

                                                                      //Subtract min from max
result = ((maxValue - minValue)*5.0)/1024.0;
return result;
}


//#define Sound A1                                                    //Sound sensor PIN A1
//float Sound_level;

void setup() {
  
  Serial.begin(9600);
  sensors.begin();
                                                                       // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  pinMode(2,OUTPUT);                                                   //Y_LED
  pinMode(3,OUTPUT);                                                   //B_LED
  pinMode(4,OUTPUT);                                                   //R_LED
  pinMode(5,OUTPUT);                                                   //Heater
  pinMode(6,INPUT);                                                    //DHT
  pinMode(7,INPUT);                                                    //Thermistor
  pinMode(A0,INPUT);                                                   //Current sensor
  //pinMode(A1,INPUT);                                                 //Sound sensor
  Serial.println("Air Mode :");                                        //default mode
  S_Mode = LOW;
}

void loop() {
  
  int chk = DHT11.read(DHT11PIN);                                      //DHT
  
  sensors.requestTemperatures();                                       //Skin thermistor
  Skin_Temp=sensors.getTempCByIndex(0);

  Voltage = getVPP();
  VRMS = (Voltage/2.0) *0.707;                                         //root 2 is 0.707
  AmpsRMS = (VRMS * 1000)/mVperAmp-0.03;
/*  Serial.print(AmpsRMS);                                             //print current in rms for calibration
  Serial.println(" Amps RMS");
*/

  if(Serial.available()){                                              // Set Mode
    T_Mode = Serial.read();
    if(T_Mode == 'S'|T_Mode == 's')
    {
    Serial.println("Skin Mode :");
    S_Mode = HIGH;
    }
  else if(T_Mode == 'A'||T_Mode == 'a'){
    Serial.println("Air Mode :");
    S_Mode = LOW;   
      }
    }
  //float n = analogRead(A1);
  //Sound_level = 20 * log10(n/5);
                                                                       //Skin Mode
  if (Skin_Temp >29 && S_Mode )                                        //High Skin Temp Warning
  {
                                                                       //Heater OFF
    digitalWrite(Heater,HIGH);
    Heater_ON = false;
    Warning = true;                                                    //Danger zone
    digitalWrite(R_LED,HIGH);                                          //Red LED ON
    Serial.println("Warning High Skin Temperature!!!");
    Serial.print("Skin_T = ");
    Serial.print(Skin_Temp);
    Serial.println("C ");    
  }
  else if(Skin_Temp >28 && S_Mode){
                                                                       //Heater OFF
    digitalWrite(Heater,HIGH);
    Heater_ON = false;
    Warning = false;                                                   //safe zone
    digitalWrite(R_LED,LOW);
    Serial.print("Skin_T = ");
    Serial.print(Skin_Temp);
    Serial.println("C ");   
    }
  else if(Skin_Temp <26 && S_Mode){
                                                                       //Heater ON
    digitalWrite(Heater,LOW);
    Heater_ON = true;
    Warning = false;                                                   //safe zone
    digitalWrite(R_LED,LOW);
    Serial.print("Skin_T = ");
    Serial.print(Skin_Temp);
    Serial.println("C ");   
    }
    else if (Skin_Temp <25 && S_Mode )                                 //Low Skin Temp Warning
  {
                                                                       //Heater ON
    digitalWrite(Heater,LOW);
    Heater_ON = true;
    Warning = true;                                                    //Danger zone
    digitalWrite(R_LED,HIGH);                                          //Red LED ON
    Serial.println("Warning LOW Skin Temperature!!!");
    Serial.print("Skin_T = ");
    Serial.print(Skin_Temp);
    Serial.println("C ");    
  }
                                                                       //Air Mode
    if (DHT11.temperature >29 && !S_Mode )                             //High Air Temp Warning
  {
                                                                       //Heater OFF
    digitalWrite(Heater,HIGH);
    Heater_ON = false;
    Warning = true;                                                    //Danger zone
    digitalWrite(R_LED,HIGH);                                          //Red LED ON
    Serial.println("Warning High Air Temperature!!!");
    Serial.print("Air_T = ");
    Serial.print((float)DHT11.temperature);
    Serial.println("C ");    
  }
  else if(DHT11.temperature >28 && !S_Mode){
                                                                       //Heater OFF
    digitalWrite(Heater,HIGH);
    Heater_ON = false;
    Warning = false;                                                   //safe zone
    digitalWrite(R_LED,LOW);
    Serial.print("Air_T = ");
    Serial.print((float)DHT11.temperature);
    Serial.println("C ");   
    }
  else if(DHT11.temperature <26 && !S_Mode){
                                                                      //Heater ON
    digitalWrite(Heater,LOW);
    Heater_ON = true;
    Warning = false;                                                  //safe zone
    digitalWrite(R_LED,LOW);
    Serial.print("Air_T = ");
    Serial.print((float)DHT11.temperature);
    Serial.println("C ");   
    }
    else if (DHT11.temperature <25 && !S_Mode )                       //Low Air Temp Warning
  {
                                                                      //Heater ON
    digitalWrite(Heater,LOW);
    Heater_ON = true;
    Warning = true;                                                   //Danger zone
    digitalWrite(R_LED,HIGH);                                         //Red LED ON
    Serial.println("Warning LOW Air Temperature!!!");
    Serial.print("Air_T = ");
    Serial.print((float)DHT11.temperature);
    Serial.println("C ");    
  }
if (DHT11.humidity>80)                                               //High Humidity Warning
  {
    Warning = true;                                                  //Danger zone
    digitalWrite(B_LED,HIGH);                                        //Blue LED ON
    Serial.println("Warning High Humidity!!!");
    Serial.print("Humidity: ");
    Serial.print((int)DHT11.humidity);
    Serial.println("%");
  }
  else if(DHT11.humidity<30){                                       //LOW Humidity Warning
    Warning = true;
    digitalWrite(B_LED,HIGH);                                       //Blue LED ON
    Serial.println("Warning LOW Humidity!!!");
    Serial.print("Humidity: ");
    Serial.print((int)DHT11.humidity);
    Serial.println("%");
    }
    else {
    Warning = false;                                                //safe zone
    digitalWrite(B_LED,LOW);                                        //Blue LED OFF
    Serial.print("Humidity: ");
    Serial.print((int)DHT11.humidity);
    Serial.println("%");
    }
    /*if (Sound_level<43 | Sound_level>45)                          //High sound level warning
  {
    Warning = true;
    digitalWrite(G_LED,HIGH);                                       //Green LED ON
    Serial.println("Warning High Sound Level!!!");
    Serial.print("DB: ");
    Serial.println(Sound_level);
*/
 if(Heater_ON && AmpsRMS<0.2){                                      //Check if Heater is working proparly
    digitalWrite(Y_LED,HIGH);                                       //Yellow LED ON
    Serial.println("Warning Heater Disconnected!!!");
  }
  else{
       digitalWrite(Y_LED,LOW);                                     //Yellow LED  OFF
      }
                                                                    //LCD
 if (S_Mode){                                                       //Skin Mode
  lcd.setCursor(0, 0);
  lcd.print("Skin_T: ");
  lcd.print(Skin_Temp);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.print((int)DHT11.humidity);
  lcd.print("%| ");
  if(Warning){
    lcd.print("alert");
    }else{
      lcd.print("Normal");
    }
 }
 else if (!S_Mode){                                                 //Air Mode
  lcd.setCursor(0, 0);
  lcd.print("Air_T = ");
  lcd.print(DHT11.temperature);
  lcd.print("C ");
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.print((int)DHT11.humidity);
  lcd.print("% | ");
  if(Warning){
    lcd.print("Alert");
    }
    else{
      lcd.print("Normal");
    }
    }

 delay(500);
 
  }

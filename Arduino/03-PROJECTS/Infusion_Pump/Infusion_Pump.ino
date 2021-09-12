
#include <LiquidCrystal.h>                                           //LCD Library

const int RS = 8, EN = 9, D4 = 10, D5 = 11, D6 = 12, D7 = 13;         //LCD PINS(8->13)

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const int Pump = 3, Volume_up = 4, Volume_down = 5,Buzzer = 6,Led=7;
int Pump_p = 1, Volume_up_p = 1, Volume_down_p = 1;
#define Pump_ON A0
#define Pump_EnA A1
int Volume = 50;
int FlowRate = 10;
int sensorInterrupt = 0;  // interrupt 0
int sensorPin       = 2; //Digital Pin 2
unsigned int SetPoint = 400; //400 milileter
float calibrationFactor = 401; //You can change according to your datasheet
volatile byte pulseCount =0;  
float flowRate = 0.0;
unsigned int flowMilliLitres =0;
unsigned long totalMilliLitres = 0;
 
unsigned long oldTime = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(Pump, INPUT_PULLUP);
  pinMode(Volume_up, INPUT_PULLUP);
  pinMode(Volume_down, INPUT_PULLUP);
  pinMode(Pump_ON, OUTPUT);
  pinMode(Pump_EnA, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
   /*The Hall-effect sensor is connected to pin 2 which uses interrupt 0. Configured to trigger on a FALLING state change (transition from HIGH
  (state to LOW state)*/
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING); //you can use Rising or Falling
}
void loop() {
  if((millis() - oldTime) > 1000)    // Only process counters once per second
  { 
    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    unsigned int frac;
   /* Serial.print("Flow rate: ");
    Serial.print(flowMilliLitres, DEC);  // Print the integer part of the variable
    Serial.print("mL/Second");
    Serial.print("\t");           
    Serial.print("Output Liquid Quantity: ");        
    Serial.print(totalMilliLitres,DEC);
    Serial.println("mL"); 
    Serial.print("\t");   */  
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
  if (digitalRead(Pump_ON) == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Volume: ");
    lcd.print(Volume);
    lcd.print("ml     ");
    lcd.setCursor(0, 1);
    if (int(totalMilliLitres)==0){
    lcd.print("Press Start     ");
    }
    else{
    lcd.print("Paused...           ");
      }
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    if (digitalRead(Pump) == LOW && digitalRead(Pump)!= Pump_p) {
    digitalWrite(Pump_ON, HIGH);
    digitalWrite(Pump_EnA, HIGH);
  }
  else if (digitalRead(Pump) == LOW && digitalRead(Pump_ON) == HIGH && digitalRead(Pump) != Pump_p) {
    digitalWrite(Pump_ON, LOW);
    digitalWrite(Pump_EnA, LOW);
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(500);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
  }
  if (digitalRead(Volume_up) == LOW && digitalRead(Volume_up) != Volume_up_p ) {
    Volume+=10;
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(50);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    Serial.println(Volume);
  }
  else if (digitalRead(Volume_down) == LOW &&  Volume != 10 && digitalRead(Volume_down) != Volume_down_p) {
    Volume-=10;
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(50);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    Serial.println(Volume);
  }
  }
  else if (digitalRead(Pump_ON) == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Volume: ");
    lcd.print(int(totalMilliLitres));
    lcd.print("/");
    lcd.print(Volume);
    lcd.print("ml ");
    lcd.setCursor(0, 1);
    lcd.print("Time_left: ");
    Serial.print(int(totalMilliLitres));
    Serial.print("/");
    Serial.println(Volume);
    if(int(flowMilliLitres)==0)
    {
    lcd.print("Wait");
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(1500);
    }
    else if(int(flowMilliLitres)!= 0){
    lcd.setCursor(0, 1);
    lcd.print("Time_left: ");
    lcd.print((Volume-totalMilliLitres)/flowMilliLitres);
    lcd.print("s        ");
    Serial.print(int(totalMilliLitres));
    Serial.print("/");
    Serial.println(Volume);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    }
    if(int(totalMilliLitres)>=Volume){
     digitalWrite(Pump_ON, LOW);
    digitalWrite(Pump_EnA, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Process is over");
    lcd.setCursor(0, 1);
    lcd.print("Restarting...       ");
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(1500);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    totalMilliLitres=0;
    Serial.println("Process is over");
    }
  if (digitalRead(Pump) == LOW && digitalRead(Pump) != Pump_p) {
    digitalWrite(Pump_ON, LOW);
    digitalWrite(Pump_EnA, LOW);
  }
  }
    



  Pump_p = digitalRead(Pump);
  Volume_up_p = digitalRead(Volume_up);
  Volume_down_p = digitalRead(Volume_down);
}
void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}

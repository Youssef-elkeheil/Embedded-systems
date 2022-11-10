int sensorIn = A0;
int mVperAmp = 200;

float Voltage = 0;
float VRMS = 0;
float AmpsRMS = 0;

void setup(){
Serial.begin(9600);
pinMode(sensorIn,INPUT);
}

void loop(){

Voltage = getVPP();
VRMS = (Voltage/2.0) *0.707; //root 2 is 0.707
AmpsRMS = (VRMS * 1000)/mVperAmp-0.03;
Serial.print(AmpsRMS);
Serial.println(" Amps RMS");
}

float getVPP()
{
float result;
int readValue; //value read from the sensor
int maxValue = 0; // store max value here
int minValue = 1024; // store min value here

uint32_t start_time = millis();
while((millis()-start_time) < 500) //sample for 0.5 Sec
{
readValue = analogRead(sensorIn);
// see if you have a new maxValue
if (readValue > maxValue)
{
/*record the maximum sensor value*/
maxValue = readValue;
}
if (readValue < minValue)
{
/*record the minimum sensor value*/
minValue = readValue;
}
}

// Subtract min from max
result = ((maxValue - minValue)*5.0)/1024.0;
return result;
}

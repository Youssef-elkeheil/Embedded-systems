#include <IRremote.h>

#define gnd 11
#define vcc 10
#define sig 9
IRrecv irrecv(sig);
decode_results result;
int IR;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(gnd,OUTPUT);
  pinMode(vcc,OUTPUT);
  irrecv.enableIRIn();
  digitalWrite(gnd,LOW);
  digitalWrite(vcc,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&result))
  {
    Serial.println(result.value,HEX);
    irrecv.resume();
  }
  delay(100);
}

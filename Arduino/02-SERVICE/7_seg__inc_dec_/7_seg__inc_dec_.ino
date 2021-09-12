#define a 4
#define b 3
#define c 2
#define d 8
#define e 9
#define f 10
#define g 11
#define up 12
#define down 13
int digit =0;
void setup() {
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(up,INPUT);
pinMode(down,INPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println(digit);
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);

if(digitalRead(up)==LOW && digit !=9)
  digit++;
else if(digitalRead(down)==LOW && digit!= 0)
  digit--;
  delay(50);
}

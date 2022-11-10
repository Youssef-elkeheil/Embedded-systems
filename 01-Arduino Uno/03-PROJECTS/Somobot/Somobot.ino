#include <IRremote.h>
//ultrasonic
#define ECHO_1              A4 
#define TRIG_1              A5 
#define ECHO_2              2
#define TRIG_2              3

int distance_1;
int distance_2;

//line follower sensors 
#define LINE_FOLLOWER_1     10
#define LINE_FOLLOWER_2     11
#define LINE_FOLLOWER_3     12
#define LINE_FOLLOWER_4     13

int line_1;
int line_2;
int line_3;

//switchs pins
#define MOTOR_SWITCH        7
#define STRATEGY_1          8
#define STRATEGY_2          9

int motor_switch;

// Motors
#define BRAKE 0
#define CW    1
#define CCW   2

//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1

short usSpeed = 150;  //default motor speed
unsigned short usMotor_Status = BRAKE;

void setup() {
  pinMode(TRIG_1, OUTPUT);
  pinMode(ECHO_1, INPUT);
  
  pinMode(TRIG_2, OUTPUT);
  pinMode(ECHO_2, INPUT);

  pinMode(LINE_FOLLOWER_1, INPUT);
  pinMode(LINE_FOLLOWER_2, INPUT);
  pinMode(LINE_FOLLOWER_3, INPUT);

  pinMode(MOTOR_SWITCH, INPUT);
  pinMode(STRATEGY_1, INPUT);
  pinMode(STRATEGY_2, INPUT);

  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);  

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);
  
  //Serial.begin(9600);
  delay(5000);
}
void loop() {
  Serial.println("Starting...");
  Ultrasonic_1();
  Ultrasonic_2();

  line_1 = digitalRead(LINE_FOLLOWER_1);
  line_2 = digitalRead(LINE_FOLLOWER_2);
  line_3 = digitalRead(LINE_FOLLOWER_3);

  motor_switch = digitalRead(MOTOR_SWITCH);
  
  Serial.println("Sensors on");
  Serial.println("Picking Strategy...");
  Strategy(digitalRead(STRATEGY_1),digitalRead(STRATEGY_2));
}


void Ultrasonic_1()
{
  long duration_1;
  digitalWrite(TRIG_1, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);
  duration_1 = pulseIn(ECHO_1, HIGH);
  distance_1 = duration_1 * 0.034 / 2;
}

void Ultrasonic_2()
{
  long duration_2;
  digitalWrite(TRIG_2, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  duration_2 = pulseIn(ECHO_2, HIGH);
  distance_2 = duration_2 * 0.034 / 2;
}


void Strategy(uint8_t strategy_1,uint8_t strategy_2)
{ 
  if(motor_switch == 0)
  {
    // do nothing
  }
  else if(strategy_1 == 0 && strategy_2 == 0)
  {
  
  }
  else if(strategy_1 == 1 && strategy_2 == 0)
  {
  
  }
  else if(strategy_1 == 0 && strategy_2 == 1)
  {
  
  }
  else if(strategy_1 == 1 && strategy_2 == 1)
  {
  
  }
  
}
void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void IncreaseSpeed()
{
  usSpeed = usSpeed + 10;
  if(usSpeed > 255)
  {
    usSpeed = 255;  
  }
  
  Serial.print("Speed +: ");
  Serial.println(usSpeed);

  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
}

void DecreaseSpeed()
{
  usSpeed = usSpeed - 10;
  if(usSpeed < 0)
  {
    usSpeed = 0;  
  }
  
  Serial.print("Speed -: ");
  Serial.println(usSpeed);

  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_2, pwm);
  }
}

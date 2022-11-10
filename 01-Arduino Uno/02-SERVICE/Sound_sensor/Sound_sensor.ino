float deb;
void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  uint32_t start_time = millis();
while((millis()-start_time) < 50) //sample for 0.1 Sec
{
  float n = analogRead(A1);
  deb = 20 * log10(n/3);
  Serial.println(deb, DEC);
}

}

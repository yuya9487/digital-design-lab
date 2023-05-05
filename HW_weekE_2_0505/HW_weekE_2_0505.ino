int sensorRead = 0;
int ledDimming = 0;
int pwmPin = 9;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(pwmPin,OUTPUT);
}

void loop()
{
  sensorRead = analogRead(A0);
  Serial.println(sensorRead);
  delay(1);
  
  if(sensorRead <20) sensorRead = 20;
  else if(sensorRead > 600)sensorRead = 600;
  
  int ledblink = map(sensorRead, 20, 600, 0, 255);
  analogWrite(9, ledblink);
}

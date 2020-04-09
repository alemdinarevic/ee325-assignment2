const int heater=2;
const int cooler=4;
const float temp=A0;

void setup()
{
  pinMode(heater, OUTPUT);
  pinMode(cooler, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop()
{
  double tempV=analogRead(temp);
  double tempValue=tempV*(5.0/1024.0);
  double ftemp=(tempValue- 0.5) * 100;
  if (ftemp>35)
  {
    digitalWrite (cooler, HIGH);
    digitalWrite (heater, LOW);
  }
  else if (ftemp<15)
  {
    digitalWrite (cooler, LOW);
    digitalWrite (heater, HIGH);
  }
  else
  {
    digitalWrite (cooler, LOW);
    digitalWrite (heater, LOW);
  }
  Serial.println (ftemp);
  
  delay (1000);
}
const int heater = 2;
const int cooler = 4;
const float temp = A0;

void setup()
{
  pinMode(heater, OUTPUT);
  pinMode(cooler, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9000);
}

void loop()
{
  double temperatureAnalog = analogRead(temp);
  double temperature = temperatureAnalog*(5.0/1024.0);
  double finalTemperature = (temperature - 0.5) * 100;
  if (finalTemperature>35)
  {
    digitalWrite (cooler, HIGH);
    digitalWrite (heater, LOW);
  }
  else if (finalTemperature<15)
  {
    digitalWrite (cooler, LOW);
    digitalWrite (heater, HIGH);
  }
  else
  {
    digitalWrite (cooler, LOW);
    digitalWrite (heater, LOW);
  }
  Serial.println (finalTemperature);
  
  delay (1000);
}
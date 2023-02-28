int sensorPin = A1;
float volt;
float ntu;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
}

void loop()
{
  volt = 0;
  for (int i = 0; i < 800; i++)
  {
    volt += ((float)analogRead(sensorPin) / 1023) * 5;
  }
  volt = volt / 800;
  volt = round_to_dp(volt, 2);
  if (volt < 2.5) {
    ntu = 3000;
  } else {
    ntu = -1120.4 * square(volt) + 5742.3 * volt - 4353.8;
  }
  Serial.print("Volt: ");
  Serial.print(volt);
  Serial.print("NTU: ");
  Serial.println(ntu);
  delay(10);
}

float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

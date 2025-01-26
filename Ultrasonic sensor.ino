#include "Ultrasonic.h"
#include "Arduino.h"
int buzzer = A0;
Ultrasonic ultrasonic(6);
void setup()
{
 Serial.begin(9600);
 pinMode(buzzer,OUTPUT);
}
void loop()
{
 long RangeInCentimeters;
 long Proximity;
 float out_put;
 RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
 Serial.println(RangeInCentimeters);//0~400cm
 Proximity = 400 - RangeInCentimeters;
 out_put = (Proximity / 400) * 255;
 analogWrite(buzzer,out_put);
 Serial.println(out_put);
 delay(250);
}
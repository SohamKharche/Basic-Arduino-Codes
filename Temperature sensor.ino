
float readPin = A0;
float calcVal;
float readVal;
float Temp;
void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal = analogRead(readPin);
calcVal = readVal * (5.0/1023.0);
Temp = calcVal / 0.01;
Serial.print("C:");
Serial.println(Temp);
delay(1000);
}


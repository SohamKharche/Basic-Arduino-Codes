int input_value = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(input_value,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(input_value,255);
delay(1000);
analogWrite(input_value,100);
delay(1000);

}

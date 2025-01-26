int state = A0;
int yel = 3;
int gre = 4;
int red = 5;
int statin;
float voltage;
void setup() {
  // put your setup code here, to run once:
pinMode(state,INPUT);
pinMode(yel,OUTPUT);
pinMode(gre,OUTPUT);
pinMode(red,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
statin = analogRead(state);
voltage = statin * 0.0049;
if (voltage >= 3.18 && voltage <= 4){
  digitalWrite(yel,HIGH);
}else if (voltage >= 4 && voltage <= 4.55){
  digitalWrite(gre,HIGH);
}else if (voltage >= 4.55){
  digitalWrite(red,HIGH);
}           
Serial.println(voltage);
delay(1000);
}

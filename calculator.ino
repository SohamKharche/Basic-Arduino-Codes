#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(0,1,2,3,4,5);
const byte ROWS = 4;
const byte COLS = 4;

char keys [ROWS] [COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'},
};
byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7,6};
Keypad myKeypad = Keypad{makeKeymap(keys), rowPins, colPins, ROWS, COLS};

bool presentValue = false;
bool next = false;
bool final = false;
String num1, num2;
int answer;
char op;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("CASIO");
  lcd.setCursor(0,1);
  lcd.print("FX-521MS");
  delay(1000);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key =='1'|| key == '2'|| key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')){
    if (presentValue != true){
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0);
      lcd.print(num1);
    }
    else{
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }

  }
  else if (key != NO_KEY && (key =='/'|| key == '*'|| key == '-' || key == '+')){
    if(presentValue == false){
      presentValue = true;
      op = key;
      lcd.setCursor(15, 0);
      lcd.print(op);
    }
  }
  else if (final == true && key != NO_KEY && key == '=' ){
    if (op == '+'){
        answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
        answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
        answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
        answer = num1.toInt() / num2.toInt();
    }
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.autoscroll();
      lcd.print(answer);
      lcd.noAutoscroll();
  }
  else if (key != NO_KEY && key == 'C'){
    lcd.clear();
  }
  
}

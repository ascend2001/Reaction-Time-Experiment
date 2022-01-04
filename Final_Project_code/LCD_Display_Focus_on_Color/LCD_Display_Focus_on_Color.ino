#include <LiquidCrystal.h>

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2, redButtonPin=8, greenButtonPin=9, blueButtonPin=10, pin[5]={7,6,13, A1, A2};
const String color[5]={"Green","Red","Blue", "White", "Yellow"};
String  randPin;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int randNumber, randDelay,redButtonState=LOW, greenButtonState=LOW, blueButtonState=LOW, yellowButtonState=LOW, whiteButtonState=LOW, state=0, randN;
unsigned long  newT, oldT, deltaT;
#define yellowButtonPin A0
#define whiteButtonPin A3
void setup() {
  lcd.begin(16,2);
  pinMode(redButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(whiteButtonPin, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  randDelay=random(100, 500);
  redButtonState=digitalRead(redButtonPin);
  greenButtonState=digitalRead(greenButtonPin);
  blueButtonState=digitalRead(blueButtonPin);
  yellowButtonState=digitalRead(yellowButtonPin);
  whiteButtonState=digitalRead(whiteButtonPin);
  if(state==0){
    randNumber=random(5);
    randN=random(5);
    randPin=color[randN];
    if(randNumber==0 && greenButtonState==LOW){
      lcd.print(randPin);
      digitalWrite(7, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==1 && redButtonState==LOW){
      lcd.print(randPin);
      digitalWrite(6, HIGH);
      oldT=millis();
      state=1;
    }
    else if (randNumber==2 && blueButtonState==LOW){
      lcd.print(randPin);
      digitalWrite(13, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==3 && yellowButtonState==LOW){
      lcd.print(randPin);
      digitalWrite(A1, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==4 && whiteButtonState==LOW){
      lcd.print(randPin);
      digitalWrite(A2, HIGH);
      oldT=millis();
      state=1;
    }
  }
  if(state==1){
    if((randNumber==0 && greenButtonState==HIGH) || (randNumber==1 && redButtonState==HIGH) || (randNumber==2 && blueButtonState==HIGH)|| (randNumber==3 && yellowButtonState==HIGH)||(randNumber==4 && whiteButtonState==HIGH)){
      newT=millis();
      lcd.clear();
      digitalWrite(pin[randNumber], LOW);
      state=0;
      deltaT=newT-oldT;
      Serial.println(deltaT);
      delay(randDelay);
    }
  }

}

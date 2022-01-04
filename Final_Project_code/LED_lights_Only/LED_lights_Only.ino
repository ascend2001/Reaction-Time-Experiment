const int redButtonPin=8, greenButtonPin=9, blueButtonPin=10, pin[5]={10,6,9,A1,A2};
int randNumber, randDelay,redButtonState=LOW, greenButtonState=LOW, blueButtonState=LOW,yellowButtonState, whiteButtonState, state=0, randN;
unsigned long  newT, oldT, deltaT;
#define yellowButtonPin A0
#define whiteButtonPin A3
void setup() {
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
    if(randNumber==0 && greenButtonState==LOW){
      digitalWrite(10, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==1 && redButtonState==LOW){
      digitalWrite(6, HIGH);
      oldT=millis();
      state=1;
    }
    else if (randNumber==2 && blueButtonState==LOW){
      digitalWrite(9, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==3 && yellowButtonState==LOW){
      digitalWrite(A1, HIGH);
      oldT=millis();
      state=1;
    }
    else if(randNumber==4 && whiteButtonState==LOW){
      digitalWrite(A2, HIGH);
      oldT=millis();
      state=1;
    }
  }
  if(state==1){
    if((randNumber==0 && greenButtonState==HIGH) || (randNumber==1 && redButtonState==HIGH) || (randNumber==2 && blueButtonState==HIGH)|| (randNumber==3 && yellowButtonState==HIGH)||(randNumber==4 && whiteButtonState==HIGH)){
      newT=millis();
      digitalWrite(pin[randNumber], LOW);
      state=0;
      deltaT=newT-oldT;
      Serial.println(deltaT);
      delay(randDelay);
    }
  }

}

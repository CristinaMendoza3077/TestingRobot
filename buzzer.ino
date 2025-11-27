int buzzerPin = 8;
int buttonPin = 2;
int buttonState;
int delayTime = 500;
int delayTime2 = 200;
int delayTime3 = 750;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 330);
    delay(delayTime2);
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 370);
    delay(delayTime3);
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 330);
    delay(delayTime2);
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 370);
    delay(delayTime3);
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 330);
    delay(delayTime2);
    tone(buzzerPin, 294);
    delay(delayTime);
    tone(buzzerPin, 247);
    delay(delayTime);
    tone(buzzerPin, 294);
    delay(delayTime3);

  }
  else{
    noTone(buzzerPin);
  }

}

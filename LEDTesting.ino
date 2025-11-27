const int buttonPin = 3;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int counter = 0;

void setup() {
pinMode(buttonPin, INPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}

void loop() {
int buttonState;
buttonState = digitalRead(buttonPin);

if (buttonState == LOW) {
counter++;
delay(250);
}

else if (counter == 0) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
}

else if (counter == 1) {
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
}

else if (counter == 2) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);
}

else if (counter == 3) {
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);
}

else if (counter == 4) {
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);
}
else {
counter = 0;
}
}

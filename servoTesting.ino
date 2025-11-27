# include <Servo.h>

Servo servo1;

int eje1 = 90;
unsigned long startTime = 0;
bool started = false;
int buzzerPin = 8;
int delayTime = 500;

void setup(){
  Serial.begin(9600);
  servo1.attach(7);
  servo1.write(90);
}
void loop(){
  //if(analogRead(0)<200 && eje1<180){
    //eje1++;
//    servo1.write(eje1);
  //}
  //if(analogRead(0)>700 && eje1>0){
    //eje1--;
    //servo1.write(eje1);
  //}
  //delay(15);


  if(!started){
    startTime = millis();
    started = true;
    Serial.println("Timer started");
  }
  if(millis() - startTime >= 10000){
    Serial.println("¡Se cumplieron los 10 segundos!");
    started = false;
    //eje1 = 150;
    eje1 = 30;
    servo1.write(eje1);
    tone(buzzerPin, 294);

  }
}

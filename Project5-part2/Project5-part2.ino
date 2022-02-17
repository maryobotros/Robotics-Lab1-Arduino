#include <Servo.h>

Servo myServo;

int potVal;
int angle;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);

  Serial.begin(9600);

  
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue >= 90){
      sensorHigh = 0;
    }
//    if(sensorValue < sensorLow){
//      sensorLow = sensorValue;
//    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  
  potVal = analogRead(sensorValue);
  Serial.print("potVa: ");
  Serial.print(potVal);

  if (potVal > 1005) {
    angle = 1;

    Serial.print(", angle: ");
    Serial.println(angle);

    myServo.write(angle);
  }
  else{
    angle = 179;
//    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);

    myServo.write(angle);
  }
  
  

//  delay(10);
}

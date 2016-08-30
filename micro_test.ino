#include <microM.h>

const int buttonPin1 = 9;
const int ledPin =  3;
int buttonState = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
}

void loop() {
 
  int buttonState = digitalRead(buttonPin1);
  static int leftSpeed = 254 , rightSpeed = 254;                          // motor control variables
  static byte leftBrake, rightBrake;


 

  if (buttonState == LOW) {

    digitalWrite(ledPin, HIGH);

    leftSpeed= 254;

delay(10);
  }
  else {

    digitalWrite(ledPin, LOW);
  }

  delay(10);
  microM.Motors(leftSpeed, rightSpeed, leftBrake, rightBrake);
}

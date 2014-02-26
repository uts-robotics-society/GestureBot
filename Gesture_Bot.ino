#include <Servo.h>

#define TIMEOUT 100

int ledPin = 13; // Set the pin to digital I/O 4
Servo servoLeft,servoRight;
int leftSpeed,rightSpeed, leftComm, rightComm;
long lastSerial;

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps
  servoLeft.attach(9);
  servoRight.attach(10);
  leftSpeed = 64;
  rightSpeed = 64;
}

void loop() {
  if(millis() - lastSerial < TIMEOUT){
    leftComm = map(leftSpeed, 0, 127, 1, 179);
    rightComm = map(rightSpeed, 0, 127, 179, 1);
  }
  else{
    leftComm = 90;
    rightComm = 90;
  }
  servoLeft.write(leftComm);
  servoRight.write(rightComm);
}

void serialEvent(){
  char inChar = (char)Serial.read();

  if(inChar & 0x80)  rightSpeed = (inChar & 0b01111111);
  else leftSpeed = inChar;
  lastSerial = millis();
}

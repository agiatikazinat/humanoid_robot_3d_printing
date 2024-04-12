#include "AFMotor.h"
#include <Servo.h>

Servo servo;
AF_DCMotor motor(4, MOTOR12_64KHZ);
int val = 100;
int target = 240;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(200);
  servo.attach(9);
  int current = map(analogRead(A2), 0, 1023, 0, 270);
  Serial.println(current);
  motor.run(BACKWARD);
  delay(1500);
  motor.run(RELEASE);
  delay(1000);
  Serial.println(map(analogRead(A2), 0, 1023, 0, 270));
  

}


void loop() {
  // put your main code here, to run repeatedly:
  int current = map(analogRead(A2), 0, 1023, 0, 270);
//  if (current < target - 2){
//    motor.run(FORWARD);
//  }
//  else if (current > target + 2){
//    motor.run(BACKWARD);
//  }
//  else {
//    motor.run(RELEASE);
//  }

//  motor.run(FORWARD);
//  delay(1000);
//  motor.run(RELEASE);
//  delay(1000);
//  Serial.println(current);
//  motor.run(BACKWARD);
//  delay(1000);
//  motor.run(RELEASE);
//  delay(1000);
  Serial.println(current);
  delay(1000);
//
//  servo.write(val);
}

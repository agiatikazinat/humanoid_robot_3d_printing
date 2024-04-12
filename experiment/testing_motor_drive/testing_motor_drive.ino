#include "AFMotor.h"
#include <Servo.h>

Servo servo;
AF_DCMotor motor(1, MOTOR12_8KHZ);
int val = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(200);
  servo.attach(9);

}


void loop() {
  // put your main code here, to run repeatedly:
  motor.run(FORWARD);
  delay(1000);
  motor.run(BACKWARD);
  delay(1000);
  motor.run(RELEASE);
  delay(1000);

  servo.write(val);
}

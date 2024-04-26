#include <Servo.h>

Servo thumb, index, middle, ring, pinky, wrist; 

void setup() {
  // put your setup code here, to run once:
  thumb.attach(0);
    index.attach(1);
    middle.attach(2);
    ring.attach(3);
    pinky.attach(4);
    wrist.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  thumb.write(0);
    index.write(0); 
    middle.write(0);
    ring.write(0);
    pinky.write(0);

  // wrist.write(0);

    delay(2000);

    thumb.write(180);
    index.write(180); 
    middle.write(180);
    ring.write(180);
    pinky.write(180);

  // wrist.write(180);

    delay(2000);

}

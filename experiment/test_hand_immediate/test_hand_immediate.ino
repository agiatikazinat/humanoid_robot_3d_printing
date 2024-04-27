#include <Servo.h>

Servo thumb, index, middle, ring, pinky, wrist; 

void setup() {
  // put your setup code here, to run once:
    thumb.attach(2);
    index.attach(3);
    middle.attach(4);
    ring.attach(5);
    pinky.attach(6);
    wrist.attach(7);
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

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
    thumb.write(90);
    index.write(80); 
    middle.write(80);
    ring.write(90);
    pinky.write(80);

  // wrist.write(0);

    delay(2000);

    //thumb.write(180);
    // index.write(180); 
    // middle.write(180);
    // ring.write(180);
    // pinky.write(180);

  // wrist.write(180);

    delay(2000);

}

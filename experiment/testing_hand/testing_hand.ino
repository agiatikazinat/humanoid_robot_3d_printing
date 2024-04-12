#include <Servo.h>

// left_hand
Servo thumb, index, middle, ring, pinky, wrist;

//right hand
Servo thumb1, index1, middle1, ring1, pinky1, wrist1;

void setup() {
  // put your setup code here, to run once:
 // Left Hand
 
  thumb.attach(6);
  index.attach(7);
  middle.attach(8);
  ring.attach(9);
  pinky.attach(10);
  wrist.attach(11);
  

// Right hand

  thumb1.attach(0);
  index1.attach(1);
  middle1.attach(2);
  ring1.attach(3);
  pinky1.attach(4);
  wrist1.attach(5);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String command = Serial.readStringUntil('\n');
    if (command == "1on"){
      thumb.write(200);
      index.write(200);
      middle.write(200);
      ring.write(200);
      pinky.write(200);
    } else if (command == "1off"){
      thumb.write(0);
      index.write(0);
      middle.write(0);
      ring.write(0);
      pinky.write(0);
    } else if (command == "2on"){
      thumb1.write(200);
      index1.write(200);
      middle1.write(200);
      ring1.write(200);
      pinky1.write(0);
    } else if (command == "2off"){
      thumb1.write(0);
      index1.write(0);
      middle1.write(0);
      ring1.write(0);
      pinky1.write(200);
    }
    Serial.println("Finish");
  
  }

  
}

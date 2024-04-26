#include <Servo.h>

// left_hand
Servo thumb, index, middle, ring, pinky, wrist;

// //right hand
// Servo thumb1, index1, middle1, ring1, pinky1, wrist1;

void setup() {
  // put your setup code here, to run once:
 // Left Hand
 
  thumb.attach(0);
  index.attach(1);
  middle.attach(2);
  ring.attach(3);
  pinky.attach(4);
  wrist.attach(5);
  

// Right hand

  // thumb1.attach(0);
  // index1.attach(1);
  // middle1.attach(2);
  // ring1.attach(3);
  // pinky1.attach(4);
  // wrist1.attach(5);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String command = Serial.readStringUntil('\n');

    // split the command
    char command_1[command.length()];
    command.toCharArray(command_1, command.length() + 1);

    char* v[3];
     int i = 0;
     char* p;
     p = strtok(command_1, " ");
     while(p && i < 3){
      v[i] = p;
      p = strtok(NULL, " ");
      i++;
     }
     String motorName = v[0];
     String method = v[1];
     String param = v[2];
    Serial.println(motorName);
    Serial.println(method);
    if (motorName == "left_hand" && method == "open"){
      thumb.write(200);
      index.write(200);
      middle.write(200);
      ring.write(200);
      pinky.write(200);
    } else if (motorName == "left_hand" && method == "close"){
      thumb.write(0);
      index.write(0);
      middle.write(0);
      ring.write(0);
      pinky.write(0);
    } else if (motorName == "right_hand" && method == "open"){
      thumb1.write(200);
      index1.write(200);
      middle1.write(200);
      ring1.write(200);
      pinky1.write(0);
    } else if (motorName == "right_hand" && method == "close"){
      thumb1.write(0);
      index1.write(0);
      middle1.write(0);
      ring1.write(0);
      pinky1.write(200);
    }
    Serial.println("Finish");
  
  }

  
}

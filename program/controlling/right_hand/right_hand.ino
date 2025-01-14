// #include "StringSplitter.h"
// #include "agiat_library.h"
// Hand right_hand(0, 1, 2, 3, 4, 5);

#include <Servo.h>

Servo thumb, index, middle, ring, pinky, wrist; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  thumb.attach(2);
  index.attach(3);
  middle.attach(4);
  ring.attach(5);
  pinky.attach(6);
  wrist.attach(7);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // get the command from controlling program 
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

    String thumb_deg;
    String index_deg;
    String middle_deg;
    String ring_deg ;
    String pinky_deg;
    String wrist_deg;

    if (motorName == "rh"){
      thumb_deg = v[1];
      index_deg = v[2];
      middle_deg = v[3];
      ring_deg = v[4];
      pinky_deg = v[5];
      wrist_deg = v[6];

      thumb.write(thumb_deg.toInt());
      index.write(index_deg.toInt());
      middle.write(middle_deg.toInt());
      ring.write(ring_deg.toInt());
      pinky.write(pinky_deg.toInt());
      wrist.write(wrist_deg.toInt());
    }

    // FOR RIGHT HAND ============================================================
    if ( motorName == "right_hand" && method.substring(0, 4) == "open"){
      thumb.write(180);
      index.write(0); 
      middle.write(180);
      ring.write(270);
      pinky.write(0);
    } 
    else if (motorName == "right_hand" && method.substring(0, 5) == "close"){
      thumb.write(0);
      index.write(180);
      middle.write(0);
      ring.write(0);
      pinky.write(180);
    }
    else if (motorName == "right_hand" && method == "wrist"){
      wrist.write(param.toInt());
    }

    

  }
}

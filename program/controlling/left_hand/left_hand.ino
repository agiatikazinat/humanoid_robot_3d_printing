// #include "StringSplitter.h"
// #include "agiat_library.h"
#include <Servo.h>
// Hand left_hand(2,3,4,5,6,7);

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

    char* v[6];
    int i = 0;
    char* p;
    p = strtok(command_1, " ");

    while(p && i < 6){
      v[i] = p;
      p = strtok(NULL, " ");
      i++;
    }
    String motorName = v[0];
    String method = v[1];
    String param = v[2];

    String thumb_deg = v[0];
    String index_deg = v[1];
    String middle_deg = v[2];
    String ring_deg = v[3];
    String pinky_deg = v[4];
    String wrist_deg = v[5];

    // FOR LEFT HAND ============================================================
    if ( motorName == "left_hand" && method.substring(0, 4) == "open"){
      thumb.write(0);
      index.write(0); 
      middle.write(0);
      ring.write(0);
      pinky.write(0);
    } 
    else if (motorName == "left_hand" && method.substring(0, 5) == "close"){
      thumb.write(180);
      index.write(180);
      middle.write(180);
      ring.write(180);
      pinky.write(180);

    }
    else if (motorName == "left_hand" && method == "wrist"){
      wrist.write(param.toInt());
    }

    else if (isDigit(motorName.charAt(0))){
      thumb.write(thumb_deg.toInt());
      index.write(index_deg.toInt());
      middle.write(middle_deg.toInt());
      ring.write(ring_deg.toInt());
      pinky.write(pinky_deg.toInt());
      wrist.write(wrist_deg.toInt());
    }
  }
  
  
}

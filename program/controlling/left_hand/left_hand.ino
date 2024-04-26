// #include "StringSplitter.h"
// #include "agiat_library.h"
#include <Servo.h>
// Hand left_hand(0, 1, 2, 3, 4, 5);

Servo thumb;
Servo index;
Servo middle, ring, pinky, wrist; 

String motorName;
String method;
String param;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  thumb.attach(0);
  index.attach(1);
  middle.attach(2);
  ring.attach(3);
  pinky.attach(4);
  wrist.attach(5);

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
    motorName = v[0];
    method = v[1];
    param = v[2];
    Serial.print("Inside loop: ");
    Serial.println(motorName);
    Serial.print(" method: ");
    Serial.println(method);
  }
  Serial.print("Outside loop: ");
  Serial.print(motorName);
  Serial.print(" method: ");
  Serial.println(method);

  // FOR LEFT HAND ============================================================
  if ( motorName == "left_hand" && method == "open"){
    thumb.write(0);
    index.write(0); 
    // middle.write(0);
    // ring.write(0);
    // pinky.write(0);
  } 
  else if (motorName == "left_hand" && method == "close"){
    thumb.write(170);
    index.write(170);
    // middle.write(170);
    // ring.write(170);
    // pinky.write(170);
  }
  // else if (motorName == "left_hand" && method == "wrist"){
  //   left_hand.servo_wrist(param.toInt());
  // }

  delay(1000);
    
}

#include "StringSplitter.h"
#include "agiat_library.h"

Hand left_hand(40, 41, 44, 45, 43, 42);
Hand right_hand(34, 33, 32, 31, 30, 29);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

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


    // FOR LEFT HAND ============================================================
    if ( motorName == "left_hand" && method == "open"){
      left_hand.open();
    } 
    else if (motorName == "left_hand" && method == "close"){
      left_hand.close();
    }
    else if (motorName == "left_hand" && method == "finger_moving"){
      left_hand.finger_moving(param);
    }
    else if (motorName == "left_hand" && method == "wrist"){
      left_hand.servo_wrist(param.toInt());
    }

    // FOR RIGHT HAND ============================================================
    if ( motorName == "right_hand" && method == "open"){
      right_hand.open();
    } 
    else if (motorName == "right_hand" && method == "close"){
      right_hand.close();
    }
    else if (motorName == "right_hand" && method == "finger_moving"){
      right_hand.finger_moving(param);
    }
    else if (motorName == "right_hand" && method == "wrist"){
      right_hand.servo_wrist(param.toInt());
    }

    

  }
}

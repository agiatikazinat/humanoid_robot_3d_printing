#include "agiat_library.h"
#include "StringSplitter.h"

// Head(int se, int m, int ue, int h, int n, int sn)
Head head(1, 0, 2, 3, 4, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(28800);

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

    // FOR HEAD ==================================================================
    if (motorName == "head" && method == "head"){
      head.servo_head(param.toInt());
    }
    else if (motorName == "head" && method == "mouth"){
      head.servo_mouth(param.toInt());
    }
    else if (motorName == "head" && method == "side_eye"){
      head.servo_side_eye(param.toInt());
    }
    else if (motorName == "head" && method == "up_eye"){
      head.servo_up_eye(param.toInt());
    }
    else if (motorName == "head" && method == "neck_side"){
      head.servo_side_neck(param.toInt());
    }
    else if (motorName == "head" && method == "neck"){
      head.servo_neck(param.toInt());
    }



  }
}

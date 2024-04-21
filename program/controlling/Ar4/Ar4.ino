#include "agiat_library.h"
#include "StringSplitter.h"

// Head(int se, int m, int ue, int h, int n, int sn)
Head head(0, 1, 2, 3, 4, 5);

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

    // Head(int se, int m, int ue, int h, int n, int sn)
    if (motorName == "head" && isDigit(method.charAt(0))){
      String se_param = v[0];
      String m_param = v[1];
      String ue_param = v[2];
      String h_param = v[3];
      String n_param = v[4];
      String sn_param = v[5];

      head.servo_head(h_param.toInt());
      head.servo_mouth(m_param.toInt());
      head.servo_side_eye(se_param.toInt());
      head.servo_up_eye(ue_param.toInt());
      head.servo_side_neck(sn_param.toInt());
      head.servo_neck(n_param.toInt());

    }

    // FOR HEAD ==================================================================
    if (motorName == "head" && method == "servo_head"){
      head.servo_head(param.toInt());
    }
    else if (motorName == "head" && method == "servo_mouth"){
      head.servo_mouth(param.toInt());
    }
    else if (motorName == "head" && method == "servo_side_eye"){
      head.servo_side_eye(param.toInt());
    }
    else if (motorName == "head" && method == "servo_up_eye"){
      head.servo_up_eye(param.toInt());
    }
    else if (motorName == "head" && method == "servo_neck_side"){
      head.servo_side_neck(param.toInt());
    }
    else if (motorName == "head" && method == "servo_neck"){
      head.servo_neck(param.toInt());
    } 
    else if (motorName == "head" && method == "set_max_limit"){
      head.setMaxLimit(param.toInt())
    }
    else if (motorName == "head" && method == "set_min_limit"){
      head.setMinLimit(param.toInt());
    }



  }
}

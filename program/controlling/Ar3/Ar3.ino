#include "StringSplitter.h"
#include "agiat_library.h"


#define POS_LSX A1
#define POS_LSY A0
#define POS_LSZ A3
#define POS_LBI A1


Shield_Motor left_shoulder_y(2, POS_LSY);
Shield_Motor left_shoulder_z(3, POS_LSZ);
Shield_Motor left_shoulder_x(1, POS_LSX);
Shield_Motor left_bicept(4, POS_LBI);


void setup() {
  Serial.begin(9600);

}

void loop() {
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

     int value = param.toInt();
     Serial.println(value);
    
    // FOR LEFT SHOULDER X ===============================================
    if (motorName == "left_shoulder_x" && method == "current"){
      Serial.println(left_shoulder_x.current_deg());
    }
    else if (motorName == "left_shoulder_x" && method == "stopMotor"){
      left_shoulder_x.stopMotor();
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_x" && method == "setSpeed"){
      left_shoulder_x.set_speed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_x" && method == "move"){
      left_shoulder_x.move_motor(param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Y ===============================================
    if (motorName == "left_shoulder_y" && method == "current"){
      Serial.println(left_shoulder_y.current_deg());
    }
    else if (motorName == "left_shoulder_y" && method == "stopMotor"){
      left_shoulder_y.stopMotor();
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_y" && method == "setSpeed"){
      left_shoulder_y.set_speed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_y" && method == "move"){
      left_shoulder_y.move_motor(param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Z ================================================
    if (motorName == "left_shoulder_z" && method == "current"){
      Serial.println(left_shoulder_z.current_deg());
    }
    else if (motorName == "left_shoulder_z" && method == "stopMotor"){
      left_shoulder_z.stopMotor();
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_z" && method == "setSpeed"){
      left_shoulder_z.set_speed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_z" && method == "move"){
      left_shoulder_z.move_motor(param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT BICEPT ====================================================
    if (motorName == "left_bicept" && method == "current"){
      Serial.println(left_bicept.current_deg());
    }
    else if (motorName == "left_bicept" && method == "stopMotor"){
      left_bicept.stopMotor();
      Serial.println("Finish");
    }
    else if (motorName == "left_bicept" && method == "setSpeed"){
      left_bicept.set_speed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_bicept" && method == "move"){
      left_bicept.move_motor(param.toInt());
      Serial.println("Finish");
    }

  }
}

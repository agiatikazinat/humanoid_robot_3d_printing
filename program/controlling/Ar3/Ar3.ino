#include "StringSplitter.h"
#include "agiat_library.h"


#define POS_LSX A0
#define POS_LSY A1
#define POS_LSZ A2
#define POS_LBI A3

AF_DCMotor leftShoulderX(1, MOTOR12_64KHZ);
AF_DCMotor leftShoulderY(2, MOTOR12_64KHZ);
AF_DCMotor leftShoulderZ(3, MOTOR12_64KHZ);
AF_DCMotor leftBicept(4, MOTOR12_64KHZ);

Shield_Motor left_shoulder_y(POS_LSY);
Shield_Motor left_shoulder_z(POS_LSZ);
Shield_Motor left_shoulder_x(POS_LSX);
Shield_Motor left_bicept(POS_LBI);


void setup() {
  Serial.begin(9600);
  leftShoulderY.setSpeed(200);
  left_shoulder_x.setDirection(-1);
  leftShoulderX.setSpeed(200);
  leftShoulderZ.setSpeed(200);
  left_shoulder_z.setDirection(-1);
  leftBicept.setSpeed(200);
  left_bicept.setDirection(-1);
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
    else if (motorName == "left_shoulder_x" && method == "setSpeed"){
      leftShoulderX.setSpeed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_x" && method == "move"){
      left_shoulder_x.move_motor(leftShoulderX, param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Y ===============================================
    if (motorName == "left_shoulder_y" && method == "current"){
      Serial.println(left_shoulder_y.current_deg());
    }
    else if (motorName == "left_shoulder_y" && method == "setSpeed"){
      leftShoulderY.setSpeed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_y" && method == "move"){
      left_shoulder_y.move_motor(leftShoulderY, param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Z ================================================
    if (motorName == "left_shoulder_z" && method == "current"){
      Serial.println(left_shoulder_z.current_deg());
    }
    else if (motorName == "left_shoulder_z" && method == "setSpeed"){
      leftShoulderZ.setSpeed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_shoulder_z" && method == "move"){
      left_shoulder_z.move_motor(leftShoulderZ, param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT BICEPT ====================================================
    if (motorName == "left_bicept" && method == "current"){
      Serial.println(left_bicept.current_deg());
    }
    else if (motorName == "left_bicept" && method == "setSpeed"){
      leftBicept.setSpeed(param.toInt());
      Serial.println("Finish");
    }
    else if (motorName == "left_bicept" && method == "move"){
      left_bicept.move_motor(leftBicept, param.toInt());
      Serial.println("Finish");
    }

  }
}

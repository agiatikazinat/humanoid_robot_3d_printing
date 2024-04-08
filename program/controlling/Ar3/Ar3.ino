#include <Servo.h>
#include "StringSplitter.h"
#include "/home/ikazinatagiat/Documents/Agiat_Ikazinat/program/controlling/library/library.h"

#define POS_LSX A0
#define POS_LSY A1
#define POS_LSZ A2
#define POS_LBI A3


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
    StringSplitter *splitter = new StringSplitter(command, ' ');

    int itemCount = splitter->getItemCount();

    String motorName = splitter->getItemAtIndex(0);
    String method = splitter->getItemAtIndex(1);
    String param;

    if (itemCount == 3){
      param = splitter->getItemAtIndex(2); 
    }

    // FOR LEFT SHOULDER X ===============================================
    if (motorName == "left_shoulder_x" && method == "current"){
      Serial.println(left_shoulder_x.current());
    }
    else if (motorName == "left_shoulder_x" && method == "stopMotor"){
      left_shoulder_x.stopMotor();
    }
    else if (motorName == "left_shoulder_x" && method == "setSpeed"){
      left_shoulder_x.setSpeed(param.toInt());
    }
    else if (motorName == "left_shoulder_x" && method == "move"){
      left_shoulder_x.move(param.toInt());
    }

    // FOR LEFT SHOULDER Y ===============================================
    if (motorName == "left_shoulder_y" && method == "current"){
      Serial.println(left_shoulder_y.current());
    }
    else if (motorName == "left_shoulder_y" && method == "stopMotor"){
      left_shoulder_y.stopMotor();
    }
    else if (motorName == "left_shoulder_y" && method == "setSpeed"){
      left_shoulder_y.setSpeed(param.toInt());
    }
    else if (motorName == "left_shoulder_y" && method == "move"){
      left_shoulder_y.move(param.toInt());
    }

    // FOR LEFT SHOULDER Z ================================================
    if (motorName == "left_shoulder_z" && method == "current"){
      Serial.println(left_shoulder_z.current());
    }
    else if (motorName == "left_shoulder_z" && method == "stopMotor"){
      left_shoulder_z.stopMotor();
    }
    else if (motorName == "left_shoulder_z" && method == "setSpeed"){
      left_shoulder_z.setSpeed(param.toInt());
    }
    else if (motorName == "left_shoulder_z" && method == "move"){
      left_shoulder_z.move(param.toInt());
    }

    // FOR LEFT BICEPT ====================================================
    if (motorName == "left_bicept" && method == "current"){
      Serial.println(left_bicept.current());
    }
    else if (motorName == "left_bicept" && method == "stopMotor"){
      left_bicept.stopMotor();
    }
    else if (motorName == "left_bicept" && method == "setSpeed"){
      left_bicept.setSpeed(param.toInt());
    }
    else if (motorName == "left_bicept" && method == "move"){
      left_bicept.move(param.toInt());
    }

  }
}

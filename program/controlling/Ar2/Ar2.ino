#include <Servo.h>
#include "StringSplitter.h"
#include "~/Document/Agiat_Ikazinat/program/controlling/library/library.h"
#include <AFMotor.h>


#define POS_RAF A0; //Right Ankle Forward
#define POS_RK A1; // Right Knee
#define POS_LK A2; //  Left Knee 
#define POS_LX A3; // Left X
#define POS_RX A4; //  Right X  
#define POS_LZ A5; // Left Z
#define POS_RSX A6; //  Right Shoulder X
#define POS_RY A7; // Right Y
#define POS_RZ A8; // Right Z
#define POS_LY A9; // Left  Y
#define POS_LAF A10; // Left Ankle Forward
#define POS_RA A11; // Right Ankle
#define POS_LA A12; //  Left Ankle
#define POS_RSY A13; // Right Shoulder Y
#define POS_RB A14; // Right Bicept
#define POS_RSZ A15;  //Right Shoulder Z-axis

void setup() {
  // put your setup code here, to run once:
  Serial.begin(14400);

  Shield_Motor right_shoulder_x(4, POS_RSX);
  Shield_Motor right_shoulder_y(3, POS_RSY);
  Shield_Motor right_shoulder_z(1, POS_RSZ);
  Shield_Motor right_bicept(2, POS_RB);

  right_ankle_forward = Motor(21, 20, 19, POS_RAF);
  right_knee = Motor(16, 17, 18, POS_RK);
  
}

void loop() {
  // put your main code here, to run repeatedly:
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

    // FOR RIGHT SHOULDER X ===================================================
    if (motorName == "right_shoulder_x" && method == "setDirection"){
      right_shoulder_x.setDirection(param.toInt());
    } 
    else if (motorName == "right_shoulder_x" && method == "setSpeed"){
      right_shoulder_x.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_x" && method == "current"){
      Serial.println(right_shoulder_x.current());
    }
    else if(motorName == "right_shoulder_x" && method == "move"){
      right_shoulder_x.move(param.toInt());
    }

    // FOR RIGHT SHOULDER Y ===================================================
    if (motorName == "right_shoulder_y" && method == "setDirection"){
      right_shoulder_y.setDirection(param.toInt());
    } 
    else if (motorName == "right_shoulder_y" && method == "setSpeed"){
      right_shoulder_y.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_y" && method == "current"){
      Serial.println(right_shoulder_y.current());
    }
    else if(motorName == "right_shoulder_y" && method == "move"){
      right_shoulder_y.move(param.toInt());
    }

    // FOR RIGHT SHOULDER Z ===================================================
    if (motorName == "right_shoulder_z" && method == "setDirection"){
      right_shoulder_z.setDirection(param.toInt());
    } 
    else if (motorName == "right_shoulder_z" && method == "setSpeed"){
      right_shoulder_z.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_z" && method == "current"){
      Serial.println(right_shoulder_z.current());
    }
    else if(motorName == "right_shoulder_z" && method == "move"){
      right_shoulder_z.move(param.toInt());
    }

    // FOR RIGHT BICEPT =======================================================
    if (motorName == "right_bicept" && method == "setDirection"){
      right_bicept.setDirection(param.toInt());
    } 
    else if (motorName == "right_bicept" && method == "setSpeed"){
      right_bicept.setSpeed(param.toInt());
    }
    else if(motorName == "right_bicept" && method == "current"){
      Serial.println(right_bicept.current());
    }
    else if(motorName == "right_bicept" && method == "move"){
      right_bicept.move(param.toInt());
    }
  }
}

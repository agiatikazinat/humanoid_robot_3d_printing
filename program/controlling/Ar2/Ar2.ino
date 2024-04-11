
#include "StringSplitter.h"
#include "/home/ikazinatagiat/Documents/Agiat_Ikazinat/program/controlling/library/library.h"



#define POS_RAF A0 //Right Ankle Forward
#define POS_RK A1 // Right Knee
#define POS_LK A2 //  Left Knee 
#define POS_LX A3 // Left X
#define POS_RX A4 //  Right X  
#define POS_LZ A5 // Left Z
#define POS_RSX A6 //  Right Shoulder X
#define POS_RY A7 // Right Y
#define POS_RZ A8 // Right Z
#define POS_LY A9 // Left  Y
#define POS_LAF A10 // Left Ankle Forward
#define POS_RA A11 // Right Ankle
#define POS_LA A12 //  Left Ankle
#define POS_RSY A13 // Right Shoulder Y
#define POS_RB A14 // Right Bicept
#define POS_RSZ A15  //Right Shoulder Z-axis

Shield_Motor right_shoulder_x(4, POS_RSX);
Shield_Motor right_shoulder_y(3, POS_RSY);
Shield_Motor right_shoulder_z(1, POS_RSZ);
Shield_Motor right_bicept(2, POS_RB);

Motor right_forward_ankle(21, 20, 19, POS_RAF);
Motor right_knee(16, 17, 18, POS_RK);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(14400);

  
  right_x = Motor(, , , POS_RX);
  right_y = Motor(, , , POS_RY);

  left_z = Motor(, , , POS_LZ);
  right_z = Motor(, , , POS_RZ);

  left_x = Motor(, , , POS_LX);
  left_y = Motor(, , , POS_LY);

  left_forward_ankle = Motor(, , , POS_LAF);
  left_knee = Motor(, , , POS_LK);

  left_side_ankle = Motor(, , , POS_LA);
  right_side_ankle = Motor(, , , POS_RA);
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

    // FOR LEFT X =============================================================
    if (motorName == "left_x" && method == "setDirection"){
      left_x.setDirection(param.toInt());
    } 
    else if (motorName == "left_x" && method == "setSpeed"){
      left_x.setSpeed(param.toInt());
    }
    else if(motorName == "left_x" && method == "current"){
      Serial.println(left_x.current());
    }
    else if(motorName == "left_x" && method == "move"){
      left_x.move(param.toInt());
    }

    // FOR RIGHT X =============================================================
    if (motorName == "right_x" && method == "setDirection"){
      right_x.setDirection(param.toInt());
    } 
    else if (motorName == "right_x" && method == "setSpeed"){
      right_x.setSpeed(param.toInt());
    }
    else if(motorName == "right_x" && method == "current"){
      Serial.println(right_x.current());
    }
    else if(motorName == "right_x" && method == "move"){
      right_x.move(param.toInt());
    }

    // FOR LEFT Y =============================================================
    if (motorName == "left_y" && method == "setDirection"){
      left_y.setDirection(param.toInt());
    } 
    else if (motorName == "left_y" && method == "setSpeed"){
      left_y.setSpeed(param.toInt());
    }
    else if(motorName == "left_y" && method == "current"){
      Serial.println(left_y.current());
    }
    else if(motorName == "left_y" && method == "move"){
      left_y.move(param.toInt());
    }

    // FOR RIGHT Y =============================================================
    if (motorName == "right_y" && method == "setDirection"){
      right_y.setDirection(param.toInt());
    } 
    else if (motorName == "right_y" && method == "setSpeed"){
      right_y.setSpeed(param.toInt());
    }
    else if(motorName == "right_y" && method == "current"){
      Serial.println(right_y.current());
    }
    else if(motorName == "right_y" && method == "move"){
      right_y.move(param.toInt());
    }

    // FOR LEFT Z =============================================================
    if (motorName == "left_z" && method == "setDirection"){
      left_z.setDirection(param.toInt());
    } 
    else if (motorName == "left_z" && method == "setSpeed"){
      left_z.setSpeed(param.toInt());
    }
    else if(motorName == "left_z" && method == "current"){
      Serial.println(left_z.current());
    }
    else if(motorName == "left_z" && method == "move"){
      left_z.move(param.toInt());
    }

    // FOR RIGHT Z =============================================================
    if (motorName == "right_z" && method == "setDirection"){
      right_z.setDirection(param.toInt());
    } 
    else if (motorName == "right_z" && method == "setSpeed"){
      right_z.setSpeed(param.toInt());
    }
    else if(motorName == "right_z" && method == "current"){
      Serial.println(right_z.current());
    }
    else if(motorName == "right_z" && method == "move"){
      right_z.move(param.toInt());
    }

    // FOR RIGHT KNEE =============================================================
    if (motorName == "right_knee" && method == "setDirection"){
      right_knee.setDirection(param.toInt());
    } 
    else if (motorName == "right_knee" && method == "setSpeed"){
      right_knee.setSpeed(param.toInt());
    }
    else if(motorName == "right_knee" && method == "current"){
      Serial.println(right_knee.current());
    }
    else if(motorName == "right_knee" && method == "move"){
      right_knee.move(param.toInt());
    }


    // FOR LEFT KNEE =============================================================
    if (motorName == "left_knee" && method == "setDirection"){
      left_knee.setDirection(param.toInt());
    } 
    else if (motorName == "left_knee" && method == "setSpeed"){
      left_knee.setSpeed(param.toInt());
    }
    else if(motorName == "left_knee" && method == "current"){
      Serial.println(left_knee.current());
    }
    else if(motorName == "left_knee" && method == "move"){
      left_knee.move(param.toInt());
    }

    // FOR LEFT FORWARD ANKLE =============================================================
    if (motorName == "left_forward_ankle" && method == "setDirection"){
      left_forward_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "left_forward_ankle" && method == "setSpeed"){
      left_forward_ankle.setSpeed(param.toInt());
    }
    else if(motorName == "left_forward_ankle" && method == "current"){
      Serial.println(left_forward_ankle.current());
    }
    else if(motorName == "left_forward_ankle" && method == "move"){
      left_forward_ankle.move(param.toInt());
    }

    // FOR RIGHT FORWARD ANKLE =============================================================
    if (motorName == "right_forward_ankle" && method == "setDirection"){
      right_forward_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "right_forward_ankle" && method == "setSpeed"){
      right_forward_ankle.setSpeed(param.toInt());
    }
    else if(motorName == "right_forward_ankle" && method == "current"){
      Serial.println(right_forward_ankle.current());
    }
    else if(motorName == "right_forward_ankle" && method == "move"){
      right_forward_ankle.move(param.toInt());
    }

    // FOR RIGHT SIDE ANKLE =============================================================
    if (motorName == "right_side_ankle" && method == "setDirection"){
      right_side_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "right_side_ankle" && method == "setSpeed"){
      right_side_ankle.setSpeed(param.toInt());
    }
    else if(motorName == "right_side_ankle" && method == "current"){
      Serial.println(right_side_ankle.current());
    }
    else if(motorName == "right_side_ankle" && method == "move"){
      right_side_ankle.move(param.toInt());
    }

    // FOR LEFT SIDE ANKLE =============================================================
    if (motorName == "left_side_ankle" && method == "setDirection"){
      left_side_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "left_side_ankle" && method == "setSpeed"){
      left_side_ankle.setSpeed(param.toInt());
    }
    else if(motorName == "left_side_ankle" && method == "current"){
      Serial.println(left_side_ankle.current());
    }
    else if(motorName == "left_side_ankle" && method == "move"){
      left_side_ankle.move(param.toInt());
    }




  }
}

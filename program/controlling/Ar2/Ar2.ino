#include "StringSplitter.h"
#include "agiat_library.h"


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

// Head(int se, int m, int ue, int h, int n, int sn)
Head head(0, 1, 2, 3, 4, 5);


Motor right_knee(21, 20, 19, POS_RAF);
Motor right_forward_ankle(16, 17, 18, POS_RK);

Motor right_x(22, 24, 26, POS_RX);
Motor right_y(32, 30, 28, POS_RY);

Motor left_z(23, 25, 27, POS_LZ);
Motor right_z(33, 31, 29, POS_RZ);

Motor left_x(35, 37, 39, POS_LX);
Motor left_y(45, 43, 41, POS_LY);

Motor left_forward_ankle(34, 36, 38, POS_LAF);
Motor left_knee(44, 42, 40, POS_LK);

Motor left_side_ankle(51, 49, 47, POS_LA);
Motor right_side_ankle(46, 48, 50, POS_RA);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // get the command from controlling program 
    String command = Serial.readStringUntil('\n');
    
    // split the command
    char command_1[command.length()];
    command.toCharArray(command_1, command.length() + 1);

    char* v[7];
    int i = 0;
    char* p;
    p = strtok(command_1, " ");
    while(p && i < 7){
      v[i] = p;
      p = strtok(NULL, " ");
      i++;
    }

    String motorName = v[0];
    String method = v[1];
    String param = v[2];

    // Head(int se, int m, int ue, int h, int n, int sn)
    if (motorName == "head" && isDigit(method.charAt(0))){
      String se_param = v[1];
      String m_param = v[2];
      String ue_param = v[3];
      String h_param = v[4];
      String n_param = v[5];
      String sn_param = v[6];

      head.servo_head(h_param.toInt());
      head.servo_mouth(m_param.toInt());
      head.servo_side_eye(se_param.toInt());
      head.servo_up_eye(ue_param.toInt());
      head.servo_side_neck(sn_param.toInt());
      head.servo_neck(n_param.toInt());

    } else {
      String motorName = v[0];
      String method = v[1];
      String param = v[2];
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
      head.setMaxLimit(param.toInt());
    }
    else if (motorName == "head" && method == "set_min_limit"){
      head.setMinLimit(param.toInt());
    }

  // FOR LEG ==================================================================
  
    // FOR LEFT X =============================================================
    if (motorName == "left_x" && method == "setDirection"){
      left_x.setDirection(param.toInt());
    } 
    else if (motorName == "left_x" && method == "setSpeed"){
      left_x.set_speed(param.toInt());
    }
    else if(motorName == "left_x" && method == "current_deg"){
      Serial.println(left_x.current_deg());
    }
    else if(motorName == "left_x" && method == "move"){
      left_x.move_motor(param.toInt());
    }

    // FOR RIGHT X =============================================================
    if (motorName == "right_x" && method == "setDirection"){
      right_x.setDirection(param.toInt());
    } 
    else if (motorName == "right_x" && method == "setSpeed"){
      right_x.set_speed(param.toInt());
    }
    else if(motorName == "right_x" && method == "current_deg"){
      Serial.println(right_x.current_deg());
    }
    else if(motorName == "right_x" && method == "move"){
      right_x.move_motor(param.toInt());
    }

    // FOR LEFT Y =============================================================
    if (motorName == "left_y" && method == "setDirection"){
      left_y.setDirection(param.toInt());
    } 
    else if (motorName == "left_y" && method == "setSpeed"){
      left_y.set_speed(param.toInt());
    }
    else if(motorName == "left_y" && method == "current_deg"){
      Serial.println(left_y.current_deg());
    }
    else if(motorName == "left_y" && method == "move"){
      left_y.move_motor(param.toInt());
    }

    // FOR RIGHT Y =============================================================
    if (motorName == "right_y" && method == "setDirection"){
      right_y.setDirection(param.toInt());
    } 
    else if (motorName == "right_y" && method == "setSpeed"){
      right_y.set_speed(param.toInt());
    }
    else if(motorName == "right_y" && method == "current_deg"){
      Serial.println(right_y.current_deg());
    }
    else if(motorName == "right_y" && method == "move"){
      right_y.move_motor(param.toInt());
    }

    // FOR LEFT Z =============================================================
    if (motorName == "left_z" && method == "setDirection"){
      left_z.setDirection(param.toInt());
    } 
    else if (motorName == "left_z" && method == "setSpeed"){
      left_z.set_speed(param.toInt());
    }
    else if(motorName == "left_z" && method == "current_deg"){
      Serial.println(left_z.current_deg());
    }
    else if(motorName == "left_z" && method == "move"){
      left_z.move_motor(param.toInt());
    }

    // FOR RIGHT Z =============================================================
    if (motorName == "right_z" && method == "setDirection"){
      right_z.setDirection(param.toInt());
    } 
    else if (motorName == "right_z" && method == "setSpeed"){
      right_z.set_speed(param.toInt());
    }
    else if(motorName == "right_z" && method == "current_deg"){
      Serial.println(right_z.current_deg());
    }
    else if(motorName == "right_z" && method == "move"){
      right_z.move_motor(param.toInt());
    }

    // FOR RIGHT KNEE =============================================================
    if (motorName == "right_knee" && method == "setDirection"){
      right_knee.setDirection(param.toInt());
    } 
    else if (motorName == "right_knee" && method == "setSpeed"){
      right_knee.set_speed(param.toInt());
    }
    else if(motorName == "right_knee" && method == "current_deg"){
      Serial.println(right_knee.current_deg());
    }
    else if(motorName == "right_knee" && method == "move"){
      right_knee.move_motor(param.toInt());
    }


    // FOR LEFT KNEE =============================================================
    if (motorName == "left_knee" && method == "setDirection"){
      left_knee.setDirection(param.toInt());
    } 
    else if (motorName == "left_knee" && method == "setSpeed"){
      left_knee.set_speed(param.toInt());
    }
    else if(motorName == "left_knee" && method == "current_deg"){
      Serial.println(left_knee.current_deg());
    }
    else if(motorName == "left_knee" && method == "move"){
      left_knee.move_motor(param.toInt());
    }

    // FOR LEFT FORWARD ANKLE =============================================================
    if (motorName == "left_forward_ankle" && method == "setDirection"){
      left_forward_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "left_forward_ankle" && method == "setSpeed"){
      left_forward_ankle.set_speed(param.toInt());
    }
    else if(motorName == "left_forward_ankle" && method == "current_deg"){
      Serial.println(left_forward_ankle.current_deg());
    }
    else if(motorName == "left_forward_ankle" && method == "move"){
      left_forward_ankle.move_motor(param.toInt());
    }

    // FOR RIGHT FORWARD ANKLE =============================================================
    if (motorName == "right_forward_ankle" && method == "setDirection"){
      right_forward_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "right_forward_ankle" && method == "setSpeed"){
      right_forward_ankle.set_speed(param.toInt());
    }
    else if(motorName == "right_forward_ankle" && method == "current_deg"){
      Serial.println(right_forward_ankle.current_deg());
    }
    else if(motorName == "right_forward_ankle" && method == "move"){
      right_forward_ankle.move_motor(param.toInt());
    }

    // FOR RIGHT SIDE ANKLE =============================================================
    if (motorName == "right_side_ankle" && method == "setDirection"){
      right_side_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "right_side_ankle" && method == "setSpeed"){
      right_side_ankle.set_speed(param.toInt());
    }
    else if(motorName == "right_side_ankle" && method == "current_deg"){
      Serial.println(right_side_ankle.current_deg());
    }
    else if(motorName == "right_side_ankle" && method == "move"){
      right_side_ankle.move_motor(param.toInt());
    }

    // FOR LEFT SIDE ANKLE =============================================================
    if (motorName == "left_side_ankle" && method == "setDirection"){
      left_side_ankle.setDirection(param.toInt());
    } 
    else if (motorName == "left_side_ankle" && method == "setSpeed"){
      left_side_ankle.set_speed(param.toInt());
    }
    else if(motorName == "left_side_ankle" && method == "current_deg"){
      Serial.println(left_side_ankle.current_deg());
    }
    else if(motorName == "left_side_ankle" && method == "move"){
      left_side_ankle.move_motor(param.toInt());
    }


  }


  
}

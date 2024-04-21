
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

Shield_Motor right_shoulder_x(POS_RSX);
Shield_Motor right_shoulder_y(POS_RSY);
Shield_Motor right_shoulder_z(POS_RSZ);
Shield_Motor right_bicept(POS_RB);

AF_DCMotor rightShoulderX(4);
AF_DCMotor rightShoulderY(3);
AF_DCMotor rightShoulderZ(1);
AF_DCMotor rightBicept(2);

int current_bicept = right_bicept.current_deg();
int current_shoulder_x = right_shoulder_x.current_deg();
int current_shoulder_y = right_shoulder_y.current_deg();
int current_shoulder_z = right_shoulder_z.current_deg();

int target_bicept = current_bicept;
int target_shoulder_x = current_shoulder_x;
int target_shoulder_y = current_shoulder_y;
int target_shoulder_z = current_shoulder_z;

const double Kp = 0.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 0.1; // Derivative gain

double error_x; 
double error_y;
double error_z;
double error_bicept;

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
  rightShoulderX.setSpeed(200);
  rightShoulderY.setSpeed(200);
  rightShoulderZ.setSpeed(200);
  rightBicept.setSpeed(200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // get the command from controlling program 
    String command = Serial.readStringUntil('\n');
    
    // split the command
    char command_1[command.length()];
    command.toCharArray(command_1, command.length() + 1);

   char* v[5];
   int i = 0;
   char* p;
   p = strtok(command_1, " ");
   while(p && i < 5){
    v[i] = p;
    p = strtok(NULL, " ");
    i++;
   }
   String motorName = "";
   String method = "";
   String param = "";

   if (motorName == "ra"){
    
      String first_param = v[1];
      String second_param = v[2];
      String third_param = v[3];
      String fourth_param = v[4];
  
      if (isDigit(first_param.charAt(0))){
        target_shoulder_x = first_param.toInt();
      }
  
      if (isDigit(second_param.charAt(0))){
        target_shoulder_y = second_param.toInt(); 
      }
  
      if (isDigit(third_param.charAt(0))){
        target_shoulder_z = third_param.toInt();
      }
  
      if (isDigit(fourth_param.charAt(0))){
        target_bicept = fourth_param.toInt();
      }
    
   } else {
      String motorName = v[0];
      String method = v[1];
      String param = v[2];
   }

   if (motorName == "current_ra"){
      Serial.print("X: "); Serial.print(right_shoulder_x.current_deg()); 
      Serial.print(" Y: "); Serial.print(right_shoulder_y.current_deg());
      Serial.print(" Z: "); Serial.print(right_shoulder_z.current_deg());
      Serial.print(" Bicept: "); Serial.println(right_bicept.current_deg());
   }

   if (motorName == "error_ra"){
      Serial.print("X Error: "); Serial.print(error_x); 
      Serial.print(" Y Error: "); Serial.print(error_y);
      Serial.print(" Z Error: "); Serial.print(error_z);
      Serial.print(" Bicept Error: "); Serial.println(error_bicept);

    }

    // FOR RIGHT SHOULDER X ===================================================
    if (motorName == "right_shoulder_x" && method == "setSpeed"){
      rightShoulderX.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_x" && method == "move"){
      right_shoulder_x.move_motor(rightShoulderX, param.toInt());
    }

    // FOR RIGHT SHOULDER Y ===================================================
    if (motorName == "right_shoulder_y" && method == "setSpeed"){
      rightShoulderY.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_y" && method == "move"){
      right_shoulder_y.move_motor(rightShoulderY, param.toInt());
    }

    // FOR RIGHT SHOULDER Z ===================================================
    if (motorName == "right_shoulder_z" && method == "setSpeed"){
      rightShoulderZ.setSpeed(param.toInt());
    }
    else if(motorName == "right_shoulder_z" && method == "move"){
      right_shoulder_z.move_motor(rightShoulderZ, param.toInt());
    }

    // FOR RIGHT BICEPT =======================================================
    if (motorName == "right_bicept" && method == "setSpeed"){
      rightBicept.setSpeed(param.toInt());
    }
    else if(motorName == "right_bicept" && method == "move"){
      right_bicept.move_motor(rightBicept, param.toInt());
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



  current_shoulder_x = right_shoulder_x.current_deg();
  current_shoulder_y = right_shoulder_y.current_deg();
  current_shoulder_z = right_shoulder_z.current_deg();
  current_bicept = right_bicept.current_deg();
  
  // Calculate errors
  error_x = target_shoulder_x - current_shoulder_x;
  error_y = target_shoulder_y - current_shoulder_y;
  error_z = target_shoulder_z - current_shoulder_z;
  error_bicept = target_bicept - current_bicept;

  // set speed =========================================================================================
  if (error_x <= 12){
    rightShoulderX.setSpeed(100);
  } else{
    rightShoulderX.setSpeed(255);
  }

  if (error_y <= 12){
    rightShoulderY.setSpeed(100);
  } else{
    rightShoulderY.setSpeed(255);
  }

  if (error_z <= 12){
    rightShoulderZ.setSpeed(100);
  } else{
    rightShoulderZ.setSpeed(255);
  }

  if (error_bicept <= 12){
    rightBicept.setSpeed(100);
  } else{
    rightBicept.setSpeed(255);
  }

  // run motor =======================================================================================

  if (error_x <= 3 && error_x >= -3){
    rightShoulderX.run(RELEASE);
  } else if(error_x > 3){
    rightShoulderX.run(FORWARD);
  } else if(error_x < -3){
    rightShoulderX.run(BACKWARD);
  } 
  
  if (error_y <= 3 && error_y >= -3){
    rightShoulderY.run(RELEASE);
  } else if(error_y > 3){
    rightShoulderY.run(BACKWARD);
  } else if(error_y < -3){
    rightShoulderY.run(FORWARD);
  }
  
  if (error_z <= 3 && error_z >= -3){
    rightShoulderZ.run(RELEASE);
  } else if(error_z > 3){
    rightShoulderZ.run(FORWARD);
  } else if(error_z < -3){
    rightShoulderZ.run(BACKWARD);
  }
  
  if (error_bicept <= 3 && error_bicept >= -3){
    rightBicept.run(RELEASE);
  } else if(error_bicept > 3){
    rightBicept.run(FORWARD);
  } else if(error_bicept < -3){
    rightBicept.run(BACKWARD);
  }

  
}

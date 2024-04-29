#include "agiat_library.h"
#include "StringSplitter.h"

#define POS_RSX A0
#define POS_RSY A1
#define POS_RSZ A2
#define POS_RBI A3

Shield_Motor right_shoulder_x(POS_RSX);
Shield_Motor right_shoulder_y(POS_RSY);
Shield_Motor right_shoulder_z(POS_RSZ);
Shield_Motor right_bicept(POS_RBI);

AF_DCMotor rightShoulderX(4, MOTOR12_64KHZ);
AF_DCMotor rightShoulderY(3, MOTOR12_64KHZ);
AF_DCMotor rightShoulderZ(1, MOTOR12_64KHZ);
AF_DCMotor rightBicept(2, MOTOR12_64KHZ);

int current_bicept = right_bicept.current_deg();
int current_shoulder_x = right_shoulder_x.current_deg();
int current_shoulder_y = right_shoulder_y.current_deg();
int current_shoulder_z = right_shoulder_z.current_deg();

int target_bicept = right_bicept.current_deg();
int target_shoulder_x = right_shoulder_x.current_deg();
int target_shoulder_y = right_shoulder_y.current_deg();
int target_shoulder_z = right_shoulder_z.current_deg();

const double Kp = 0.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 0.1; // Derivative gain

double error_x = 0; 
double error_y = 0;
double error_z = 0;
double error_bicept = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  rightShoulderX.setSpeed(200);
  rightShoulderY.setSpeed(200);
  rightShoulderZ.setSpeed(200);
  rightBicept.setSpeed(200);

  target_bicept = right_bicept.current_deg();
  target_shoulder_x = right_shoulder_x.current_deg();
  target_shoulder_y = right_shoulder_y.current_deg();
  target_shoulder_z = right_shoulder_z.current_deg();

  Serial.print("X target: "); Serial.print(target_shoulder_x); 
  Serial.print(" Y target: "); Serial.print(target_shoulder_y);
  Serial.print(" Z target: "); Serial.print(target_shoulder_z);
  Serial.print(" Bicept target: "); Serial.println(target_bicept);

  Serial.print("X: "); Serial.print(right_shoulder_x.current_deg()); 
  Serial.print(" Y: "); Serial.print(right_shoulder_y.current_deg());
  Serial.print(" Z: "); Serial.print(right_shoulder_z.current_deg());
  Serial.print(" Bicept: "); Serial.println(right_bicept.current_deg());

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
    String motorName = v[0];
    String method = v[1];
    String param = v[2];

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
      
      Serial.println(target_shoulder_x);
      
    } 

    if (motorName.substring(0, 10) == "current_ra"){
      Serial.print("X: "); Serial.print(right_shoulder_x.current_deg()); 
      Serial.print(" Y: "); Serial.print(right_shoulder_y.current_deg());
      Serial.print(" Z: "); Serial.print(right_shoulder_z.current_deg());
      Serial.print(" Bicept: "); Serial.println(right_bicept.current_deg());
      
    } 

    if (motorName.substring(0, 8) == "error_ra"){
      Serial.print("X Error: "); Serial.print(error_x); 
      Serial.print(" Y Error: "); Serial.print(error_y);
      Serial.print(" Z Error: "); Serial.print(error_z);
      Serial.print(" Bicept Error: "); Serial.println(error_bicept);

    }

    if (motorName.substring(0, 9) == "target_ra"){
      Serial.print("X target: "); Serial.print(target_shoulder_x); 
      Serial.print(" Y target: "); Serial.print(target_shoulder_y);
      Serial.print(" Z target: "); Serial.print(target_shoulder_z);
      Serial.print(" Bicept target: "); Serial.println(target_bicept);
      
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

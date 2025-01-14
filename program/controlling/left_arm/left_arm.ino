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


int current_bicept = left_bicept.current_deg();
int current_shoulder_x = left_shoulder_x.current_deg();
int current_shoulder_y = left_shoulder_y.current_deg();
int current_shoulder_z = left_shoulder_z.current_deg();


int target_bicept = current_bicept;
int target_shoulder_x = current_shoulder_x;
int target_shoulder_y = current_shoulder_y;
int target_shoulder_z = current_shoulder_z;


// Define the parameters for PID control
const double Kp = 0.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 0.1; // Derivative gain

//double previousErrorX = current_shoulder_x; // Error in previous iteration for motor 1
//double previousErrorY = current_shoulder_y; // Error in previous iteration for motor 2
//double previousErrorZ = current_shoulder_z;
//double previousErrorBicept = current_bicept;


double integral1 = 0; // Integral term for motor 1
double integral2 = 0; // Integral term for motor 2

double error_x; 
double error_y;
double error_z;
double error_bicept;


void setup() {
  Serial.begin(9600);

  leftShoulderY.setSpeed(200);
  leftShoulderX.setSpeed(200);
  leftShoulderZ.setSpeed(200);
  leftBicept.setSpeed(200);
  left_shoulder_x.setDirection(-1);
  left_bicept.setDirection(-1);

  target_bicept = left_bicept.current_deg();
  target_shoulder_x = left_shoulder_x.current_deg();
  target_shoulder_y = left_shoulder_y.current_deg();
  target_shoulder_z = left_shoulder_z.current_deg();

}

void loop() {

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

    if (motorName == "la"){

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
      
      
    }

    if (motorName.substring(0, 10) == "current_la"){
      Serial.print("X: "); Serial.print(left_shoulder_x.current_deg()); 
      Serial.print(" Y: "); Serial.print(left_shoulder_y.current_deg());
      Serial.print(" Z: "); Serial.print(left_shoulder_z.current_deg());
      Serial.print(" Bicept: "); Serial.println(left_bicept.current_deg());
      
    } 

    if (motorName.substring(0, 8) == "error_la"){
      Serial.print("X Error: "); Serial.print(error_x); 
      Serial.print(" Y Error: "); Serial.print(error_y);
      Serial.print(" Z Error: "); Serial.print(error_z);
      Serial.print(" Bicept Error: "); Serial.println(error_bicept);

    }
    
    // FOR LEFT SHOULDER X ===============================================
    if (motorName == "left_shoulder_x" && method == "current"){
      Serial.println(left_shoulder_x.current_deg());
    }
    else if (motorName == "left_shoulder_x" && method == "move"){
      target_shoulder_x = param.toInt();
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Y ===============================================
    if (motorName == "left_shoulder_y" && method == "current"){
      Serial.println(left_shoulder_y.current_deg());
    }
    else if (motorName == "left_shoulder_y" && method == "move"){
      target_shoulder_y = param.toInt();
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Z ================================================
    if (motorName == "left_shoulder_z" && method == "current"){
      Serial.println(left_shoulder_z.current_deg());
    }
    else if (motorName == "left_shoulder_z" && method == "move"){
      target_shoulder_z = param.toInt();
      Serial.println("Finish");
    }

    // FOR LEFT BICEPT ====================================================
    if (motorName == "left_bicept" && method == "current"){
      Serial.println(left_bicept.current_deg());
    }
    else if (motorName == "left_bicept" && method == "move"){
      target_bicept = param.toInt(); 
      Serial.println("Finish");
    }

  }


  current_shoulder_x = left_shoulder_x.current_deg();
  current_shoulder_y = left_shoulder_y.current_deg();
  current_shoulder_z = left_shoulder_z.current_deg();
  current_bicept = left_bicept.current_deg();
  
  // Calculate errors
  error_x = target_shoulder_x - current_shoulder_x;
  error_y = target_shoulder_y - current_shoulder_y;
  error_z = target_shoulder_z - current_shoulder_z;
  error_bicept = target_bicept - current_bicept;

  // set speed =============================================================
  if (error_x <= 12){
    leftShoulderX.setSpeed(100);
  } else{
    leftShoulderX.setSpeed(220);
  }

  if (error_y <= 12){
    leftShoulderY.setSpeed(100);
  } else{
    leftShoulderY.setSpeed(220);
  }

  if (error_z <= 12){
    leftShoulderZ.setSpeed(100);
  } else{
    leftShoulderZ.setSpeed(220);
  }

  if (error_bicept <= 12){
    leftBicept.setSpeed(100);
  } else{
    leftBicept.setSpeed(220);
  }


  // Run motor ==============================================================

  if (error_x <= 3 && error_x >= -3){
    leftShoulderX.run(RELEASE);
  } else if(error_x > 3){
    leftShoulderX.run(FORWARD);
  } else if(error_x < -3){
    leftShoulderX.run(BACKWARD);
  } 
  
  if (error_y <= 3 && error_y >= -3){
    leftShoulderY.run(RELEASE);
  } else if(error_y > 3){
    leftShoulderY.run(BACKWARD);
  } else if(error_y < -3){
    leftShoulderY.run(FORWARD);
  }
  
  if (error_z <= 3 && error_z >= -3){
    leftShoulderZ.run(RELEASE);
  } else if(error_z > 3){
    leftShoulderZ.run(FORWARD);
  } else if(error_z < -3){
    leftShoulderZ.run(BACKWARD);
  }
  
  if (error_bicept <= 3 && error_bicept >= -3){
    leftBicept.run(RELEASE);
  } else if(error_bicept > 3){
    leftBicept.run(FORWARD);
  } else if(error_bicept < -3){
    leftBicept.run(BACKWARD);
  }


//  // Calculate PID control outputs
//  double output_x = Kp * error_x + Kd * (error_x - previousErrorX); // Ki * integral1
//  double output_y = Kp * error_y + Kd * (error_y - previousErrorY);
//  double output_z = Kp * error_z + Kd * (error_z - previousErrorZ);
//  double output_bicept = Kp * error_bicept + Kd * (error_bicept - previousErrorBicept);
//
//  // Update integral terms
//  integral1 += error_x;
//  integral2 += error_y;
//
  // Update previous errors
//  previousErrorX = error_x;
//  previousErrorY = error_y;
//  previousErrorZ = error_z;
//  previousErrorBicept = error_bicept;
//
//  // Limit the outputs to the motor speed range (-255 to 255)
//  int motorSpeedX = constrain(output_x, -255, 255);
//  int motorSpeedY = constrain(output_y, -255, 255);
//  int motorSpeedZ = constrain(output_z, -255, 255);
//  int motorSpeedBicept = constrain(output_bicept, -255, 255);

  

  // Apply control signals to the motors
  // PID
//  if (error_x <= 2 && error_x >= -2){
//    motorSpeedX = 0;
//  }
//  if (error_y <= 2 && error_y >= -2){
//    motorSpeedY = 0;
//  }
//  if (error_z <= 2 && error_z >= -2){
//    motorSpeedZ = 0;
//  }
//  if (error_bicept <= 2 && error_bicept >= -2){
//    motorSpeedBicept = 0;
//  }
//
//  if (motorSpeedX > 0) {
//    leftShoulderX.run(FORWARD);
//    leftShoulderX.setSpeed(motorSpeedX);
//  } else if (motorSpeedX < 0) {
//    leftShoulderX.run(BACKWARD);
//    leftShoulderX.setSpeed(-motorSpeedX);
//  } else if(motorSpeedX == 0) {
//    leftShoulderX.run(RELEASE);
//  }
//  
//  if (motorSpeedY > 0) {
//    leftShoulderY.run(FORWARD);
//    leftShoulderY.setSpeed(motorSpeedY);
//  } else if (motorSpeedY < 0) {
//    leftShoulderY.run(BACKWARD);
//    leftShoulderY.setSpeed(-motorSpeedY);
//  } else if(motorSpeedY == 0){
//    leftShoulderY.run(RELEASE);
//  }
//
//  if (motorSpeedZ > 0) {
//    leftShoulderZ.run(FORWARD);
//    leftShoulderZ.setSpeed(motorSpeedZ);
//  } else if (motorSpeedX < 0) {
//    leftShoulderZ.run(BACKWARD);
//    leftShoulderZ.setSpeed(-motorSpeedZ);
//  } else if(motorSpeedZ == 0){
//    leftShoulderZ.run(RELEASE);
//  }
//  
//  if (motorSpeedBicept > 0) {
//    leftBicept.run(FORWARD);
//    leftBicept.setSpeed(motorSpeedBicept);
//  } else if (motorSpeedBicept < 0) {
//    leftBicept.run(BACKWARD);
//    leftBicept.setSpeed(-motorSpeedBicept);
//  } else if(motorSpeedBicept == 0){
//    leftBicept.run(RELEASE);
//  }

  // Serial.print("X: "); Serial.print(left_shoulder_x.current_deg()); 
  // Serial.print(" Y: "); Serial.print(left_shoulder_y.current_deg());
  // Serial.print(" Z: "); Serial.print(left_shoulder_z.current_deg());
  // Serial.print(" Bicept: "); Serial.println(left_bicept.current_deg());

  delay(1000);

  



}

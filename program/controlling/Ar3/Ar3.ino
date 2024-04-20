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

int target_bicept = left_bicept.current_deg();
int target_shoulder_x = left_shoulder_x.current_deg();
int target_shoulder_y = left_shoulder_y.current_deg();
int target_shoulder_z = left_shoulder_z.current_deg();

int current_bicept = left_bicept.current_deg();
int current_shoulder_x = left_shoulder_x.current_deg();
int current_shoulder_y = left_shoulder_y.current_deg();
int current_shoulder_z = left_shoulder_z.current_deg();

// Define the parameters for PID control
const double Kp = 0.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 0.1; // Derivative gain

double previousErrorX = 0; // Error in previous iteration for motor 1
double previousErrorY = 0; // Error in previous iteration for motor 2
double previousErrorZ = 0;
double previousErrorBicept = 0;

double integral1 = 0; // Integral term for motor 1
double integral2 = 0; // Integral term for motor 2

bool numeric = false;

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

    char* v[4];
    int i = 0;
    char* p;
    p = strtok(command_1, " ");
    while(p){
      v[i] = p;
      p = strtok(NULL, " ");
    }

    String motorName = ""; 
    String method = "";
    String param = "";

    if (isDigit(command.charAt(0))){

      String first_param = v[0];
      String second_param = v[1];
      String third_param = v[2];
      String fourth_param = v[3];

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

      motorName = v[0]; 
      method = v[1];
      param = v[2];

    }

    if (motorName == "current"){
      Serial.print("X: "); Serial.print(left_shoulder_x.current_deg()); 
      Serial.print(" Y: "); Serial.print(left_shoulder_y.current_deg());
      Serial.print(" Z: "); Serial.print(left_shoulder_z.current_deg());
      Serial.print(" Bicept: "); Serial.println(left_bicept.current_deg());
      
    }
    
    // FOR LEFT SHOULDER X ===============================================
    if (motorName == "left_shoulder_x" && method == "current"){
      Serial.println(left_shoulder_x.current_deg());
    }
    else if (motorName == "left_shoulder_x" && method == "move"){
      target_shoulder_x = 
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Y ===============================================
    if (motorName == "left_shoulder_y" && method == "current"){
      Serial.println(left_shoulder_y.current_deg());
    }
    else if (motorName == "left_shoulder_y" && method == "move"){
      left_shoulder_y.move_motor(leftShoulderY, param.toInt());
      Serial.println("Finish");
    }

    // FOR LEFT SHOULDER Z ================================================
    if (motorName == "left_shoulder_z" && method == "current"){
      Serial.println(left_shoulder_z.current_deg());
    }
    else if (motorName == "left_shoulder_z" && method == "move"){
      left_shoulder_z.move_motor(leftShoulderZ, param.toInt());
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
  double error_x = target_shoulder_x - current_shoulder_x;
  double error_y = target_shoulder_y - current_shoulder_y;
  double error_z = target_shoulder_z - current_shoulder_z;
  double error_bicept = target_bicept - current_bicept;

  // Calculate PID control outputs
  double output_x = Kp * error_x + Kd * (error_x - previousErrorX); // Ki * integral1
  double output_y = Kp * error_y + Kd * (error_y - previousErrorY);
  double output_z = Kp * error_z + Kd * (error_z - previousErrorZ);
  double output_bicept = Kp * error_bicept + Kd * (error_bicept - previousErrorBicept);

  // Update integral terms
  integral1 += error_x;
  integral2 += error_y;

  // Update previous errors
  previousErrorX = error_x;
  previousErrorY = error_y;
  previousErrorZ = error_z;
  previousErrorBicept = error_bicept;

  // Limit the outputs to the motor speed range (-255 to 255)
  int motorSpeedX = constrain(output_x, -255, 255);
  int motorSpeedY = constrain(output_y, -255, 255);
  int motorSpeedZ = constrain(output_z, -255, 255);
  int motorSpeedBicept = constrain(output_bicept, -255, 255);

  // Apply control signals to the motors

  if (error_x <= 2 && error_x >= -2){
    motorSpeedX = 0;
  }
  if (error_y <= 2 && error_y >= -2){
    motorSpeedY = 0;
  }
  if (error_z <= 2 && error_z >= -2){
    motorSpeedZ = 0;
  }
  if (error_bicept <= 2 && error_bicept >= -2){
    motorSpeedBicept = 0;
  }

  if (motorSpeedX >= 0) {
    leftShoulderX.run(FORWARD);
    leftShoulderX.setSpeed(motorSpeedX);
  } else if (motorSpeedX < 0) {
    leftShoulderX.run(BACKWARD);
    leftShoulderX.setSpeed(-motorSpeedX);
  }
  
  if (motorSpeedY >= 0) {
    leftShoulderY.run(FORWARD);
    leftShoulderY.setSpeed(motorSpeedY);
  } else if (motorSpeedY < 0) {
    leftShoulderY.run(BACKWARD);
    leftShoulderY.setSpeed(-motorSpeedY);
  }

  if (motorSpeedZ >= 0) {
    leftShoulderZ.run(FORWARD);
    leftShoulderZ.setSpeed(motorSpeedZ);
  } else if (motorSpeedX < 0) {
    leftShoulderZ.run(BACKWARD);
    leftShoulderZ.setSpeed(-motorSpeedZ);
  }
  
  if (motorSpeedBicept >= 0) {
    leftBicept.run(FORWARD);
    leftBicept.setSpeed(motorSpeedBicept);
  } else if (motorSpeedBicept < 0) {
    leftBicept.run(BACKWARD);
    leftBicept.setSpeed(-motorSpeedBicept);
  }




}

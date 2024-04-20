#include "AFMotor.h"
#include "Servo.h"
#include "StringSplitter.h"

AF_DCMotor myMotor1(4, MOTOR12_64KHZ);
AF_DCMotor myMotor2(2, MOTOR12_64KHZ);

// Define the pins for potentiometer input
const int potPin1 = A0; // Analog pin for reading potentiometer value for motor 1
const int potPin2 = A1; // Analog pin for reading potentiometer value for motor 2

// Define the parameters for PID control
const double Kp = 1.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 2; // Derivative gain

// Define variables for PID control
double targetPosition1 = 0; // Target position for motor 1
double targetPosition2 = 0; // Target position for motor 2

double currentPosition1 = 0; // Current position read from potentiometer for motor 1
double currentPosition2 = 0; // Current position read from potentiometer for motor 2

double previousError1 = 0; // Error in previous iteration for motor 1
double previousError2 = 0; // Error in previous iteration for motor 2

double integral1 = 0; // Integral term for motor 1
double integral2 = 0; // Integral term for motor 2

bool numeric = false;

Servo myServo;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {

  if (Serial.available() > 0){
    String command = Serial.readStringUntil('\n');
    
    if (isDigit(command.charAt(0))){
      numeric = true;
    } else {
      numeric = false;
    }

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
     
     String v1 = v[0];
     String v2 = v[1];
     String v3 = v[2];
     if (numeric){
      targetPosition1 = v1.toInt();
      targetPosition2 = v2.toInt();
      Serial.print(targetPosition1); Serial.print(" ");
      Serial.println(targetPosition2);
      myServo.write(targetPosition2);
      Serial.println(numeric);
     }

  }

  
  // read potentiometer values 
  currentPosition1 = map(analogRead(potPin1), 0, 1023, 0, 255);
  currentPosition2 = map(analogRead(potPin2), 0, 1023, 0, 255);
  Serial.println(currentPosition1);
  // Calculate errors
  double error1 = targetPosition1 - currentPosition1;
  double error2 = targetPosition2 - currentPosition2;

  // Calculate PID control outputs
  double output1 = Kp * error1 +  Kd * (error1 - previousError1);
  double output2 = Kp * error2 + Ki * integral2 + Kd * (error2 - previousError2);

  // Update integral terms
  integral1 += error1;
  integral2 += error2;

  // Update previous errors
  previousError1 = error1;
  previousError2 = error2;

  // Limit the outputs to the motor speed range (-255 to 255)
  int motorSpeed1 = constrain(output1, -255, 255);
  int motorSpeed2 = constrain(output2, -255, 255);

  // Apply control signals to the motors
  if (motorSpeed1 >= 0) {
    myMotor1.run(FORWARD);
    myMotor1.setSpeed(motorSpeed1);
  } else {
    myMotor1.run(BACKWARD);
    myMotor1.setSpeed(-motorSpeed1);
  }
  
  if (motorSpeed2 >= 0) {
    myMotor2.run(FORWARD);
    myMotor2.setSpeed(motorSpeed2);
  } else {
    myMotor2.run(BACKWARD);
    myMotor2.setSpeed(-motorSpeed2);
  }

  // Print debug information
  // Serial.print("Motor 1 - Target Position: ");
  // Serial.print(targetPosition1);
  // Serial.print(", Current Position: ");
  // Serial.print(currentPosition1);
  // Serial.print(", Motor Speed: ");
  // Serial.println(motorSpeed1);

  // Serial.print("Motor 2 - Target Position: ");
  // Serial.print(targetPosition2);
  // Serial.print(", Current Position: ");
  // Serial.print(currentPosition2);
  // Serial.print(", Motor Speed: ");
  // Serial.println(motorSpeed2);

  // Delay between iterations
  delay(1000); // Adjust as needed
}

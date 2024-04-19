#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Create the motor objects
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

// Define the pins for potentiometer input
const int potPin1 = A0; // Analog pin for reading potentiometer value for motor 1
const int potPin2 = A1; // Analog pin for reading potentiometer value for motor 2

// Define the parameters for PID control
const double Kp = 0.5; // Proportional gain
const double Ki = 0.2; // Integral gain
const double Kd = 0.1; // Derivative gain

// Define variables for PID control
double targetPosition1 = 0; // Target position for motor 1
double targetPosition2 = 0; // Target position for motor 2
double currentPosition1 = 0; // Current position read from potentiometer for motor 1
double currentPosition2 = 0; // Current position read from potentiometer for motor 2
double previousError1 = 0; // Error in previous iteration for motor 1
double previousError2 = 0; // Error in previous iteration for motor 2
double integral1 = 0; // Integral term for motor 1
double integral2 = 0; // Integral term for motor 2

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize motor shield
  AFMS.begin(); 
}

void loop() {
  // Read potentiometer values
  currentPosition1 = analogRead(potPin1);
  currentPosition2 = analogRead(potPin2);
  
  // Map potentiometer values to the desired position range (0-255)
  targetPosition1 = map(currentPosition1, 0, 1023, 0, 255);
  targetPosition2 = map(currentPosition2, 0, 1023, 0, 255);

  // Calculate errors
  double error1 = targetPosition1 - currentPosition1;
  double error2 = targetPosition2 - currentPosition2;

  // Calculate PID control outputs
  double output1 = Kp * error1 + Ki * integral1 + Kd * (error1 - previousError1);
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
    motor1->run(FORWARD);
    motor1->setSpeed(motorSpeed1);
  } else {
    motor1->run(BACKWARD);
    motor1->setSpeed(-motorSpeed1);
  }
  
  if (motorSpeed2 >= 0) {
    motor2->run(FORWARD);
    motor2->setSpeed(motorSpeed2);
  } else {
    motor2->run(BACKWARD);
    motor2->setSpeed(-motorSpeed2);
  }

  // Print debug information
  Serial.print("Motor 1 - Target Position: ");
  Serial.print(targetPosition1);
  Serial.print(", Current Position: ");
  Serial.print(currentPosition1);
  Serial.print(", Motor Speed: ");
  Serial.println(motorSpeed1);

  Serial.print("Motor 2 - Target Position: ");
  Serial.print(targetPosition2);
  Serial.print(", Current Position: ");
  Serial.print(currentPosition2);
  Serial.print(", Motor Speed: ");
  Serial.println(motorSpeed2);

  // Delay between iterations
  delay(10); // Adjust as needed
}

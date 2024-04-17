#include "StringSplitter.h"
#include <AFMotor.h>

#define POS_LSX A0
int dir = -1;
bool ok = false;

int SMotor_move(AF_DCMotor dcMotor, int target, int pos){
  int current_degree = map(analogRead(pos), 0, 1023, 0, 270);
  if (current_degree > target + 2 ) {
      while(current_degree > target + 2 ) {
          if (dir == 1){
              dcMotor.run(FORWARD);
          } else if (dir == -1){
              dcMotor.run(BACKWARD);
          }
          current_degree = map(analogRead(pos), 0, 1023, 0, 270);
          Serial.println(current_degree);
      }
      dcMotor.run(RELEASE);
  } else if (current_degree < target - 2 ){
      while(current_degree < target - 2 ){
          if (dir == 1){
              dcMotor.run(BACKWARD);
          } else if (dir == -1){
              dcMotor.run(FORWARD);
          }
          current_degree  = map(analogRead(pos), 0, 1023, 0, 270);
          Serial.println(current_degree);
      }
      dcMotor.run(RELEASE);
  } else {
      dcMotor.run(RELEASE); 
  }
}

AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor myMotor(1, MOTOR12_64KHZ);

//Shield_Motor motor(1, POS_LSX);

//AF_DCMotor dcMotor(1, POS_LSX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myMotor.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:

  SMotor_move(myMotor, 110, POS_LSX);
  
//if (ok){
//     
//  if (current_degree > target + 2 ) {
//      while(current_degree > target + 2 ) {
//          if (dir == 1){
//              dcMotor.run(FORWARD);
//          } else if (dir == -1){
//              dcMotor.run(BACKWARD);
//          }
//          current_degree = map(analogRead(A0), 0, 1023, 0, 270);
//          Serial.println(current_degree);
//      }
//      dcMotor.run(RELEASE);
//  } else if (current_degree < target - 2 ){
//      while(current_degree < target - 2 ){
//          if (dir == 1){
//              dcMotor.run(BACKWARD);
//          } else if (dir == -1){
//              dcMotor.run(FORWARD);
//          }
//          current_degree  = map(analogRead(A0), 0, 1023, 0, 270);
//          Serial.println(current_degree);
//      }
//      dcMotor.run(RELEASE);
//  } else {
//      dcMotor.run(RELEASE); 
//  }
//
//}  



//  if (Serial.available() > 0){
//    // get the command from controlling program 
//    String command = Serial.readStringUntil('\n');
//    
//    // split the command
//    char command_1[command.length()];
//    command.toCharArray(command_1, command.length() + 1);
//
//   char* v[3];
//   int i = 0;
//   char* p;
//   p = strtok(command_1, " ");
//   while(p && i < 3){
//    v[i] = p;
//    p = strtok(NULL, " ");
//    i++;
//   }
//   String motorName = v[0];
//   String method = v[1];
//   String param = v[2];
//
//   Serial.print(motorName); Serial.print(" "); Serial.println(method);
//
//
//   if (motorName == "motor" && method == "current"){
//      Serial.println(motor.current_deg());
//    }
//    else if (motorName == "motor" && method == "move"){
//      Serial.println(param);
//      motor.move_motor(param.toInt());
//      Serial.println("Finish");
//    }
//
//
//
//  }

}

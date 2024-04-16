#include "StringSplitter.h"
#include <AFMotor.h>

int target = 100;
#define POS_LSX A0
int dir = 1;
bool ok = false;
class Shield_Motor{
    private:
        
        int _direction = 1;
        int _potPin;
        int _delta = 2;
        int _current;
        int _min_limit, _max_limit;

    public:
        AF_DCMotor dcMotor;
        Shield_Motor(uint8_t motorNum, int potPin) : dcMotor(motorNum, MOTOR12_64KHZ) {
            _potPin = potPin;
        }
        
        int current_deg(){
            _current = map(analogRead(_potPin), 0, 1023, 0, 270);  
            return _current;
        }
        
        void stopMotor(){
            dcMotor.run(RELEASE);
        }

        void move_motor(int deg){
          int current_degree = current_deg();
     
          if (current_degree > deg + _delta && current_degree > _min_limit) {
              while(current_degree > deg + _delta ) {
                  if (_direction == 1){
                      dcMotor.run(BACKWARD);
                  } else if (_direction == -1){
                      dcMotor.run(FORWARD);
                  }
                  current_degree = current_deg();
                  Serial.println(current_degree);
              }
              dcMotor.run(RELEASE);
          } else if (current_degree < deg - _delta && current_degree < _max_limit ){
              while(current_degree < deg - _delta ){
                  if (_direction == 1){
                      dcMotor.run(FORWARD);
                  } else if (_direction == -1){
                      dcMotor.run(BACKWARD);
                  }
                  current_degree  = current_deg();
                  Serial.println(current_degree);
              }
              dcMotor.run(RELEASE);
          } else {
              dcMotor.run(RELEASE); 
          }
        }

};


Shield_Motor motor(1, POS_LSX);

//AF_DCMotor dcMotor(1, POS_LSX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

//  dcMotor.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.move_motor(110);
  
    int current_degree = map(analogRead(A0), 0, 1023, 0, 270);
          Serial.println(current_degree);

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

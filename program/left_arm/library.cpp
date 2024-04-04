// library.cpp
#include "library.h"

Motor::Motor(int en, int in1, int in2, int potPin){
    en = en;
    in1 = in1;
    in2 = in2;
    potPin = potPin;
    current = map(analogRead(potPin), 0, 1023, 0, 270);   
    pinMode(en, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(potPin, INPUT);
}    
int Motor::current(){
    current = map(analogRead(potPin), 0, 1023, 0, 270);  
    return current;
}

void Motor::stopMotor(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void Motor::setSpeed(int speed){
    speed = speed;
}

void Motor::move(int degree){
    int current_deg = Motor::current();
    if (current_deg > deg - 2){
        while(current_deg > deg - 2 ) {
            if (direction == 1){
                digitalWrite(en, speed);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            } else if (direction == -1){
                digitalWrite(en, speed);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            }
        }
    } else if (current_deg < degree + 2){
        while(current_def < deg + 2){
            if (direction == 1){
                digitalWrite(en, speed);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            } else if (direction == -1){
                digitalWrite(en, speed);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            }
        }
    } else {
        Motor::stopMotor();
    }
}

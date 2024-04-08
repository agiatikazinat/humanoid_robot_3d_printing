#include "library.h"
#include <Servo.h>
#include <AFMotor.h>
// MOTOR SET UP =============================================================================================

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

void Motor::setDirection(int direct){
    _direction = direct;
}

void Motor::stopMotor(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void Motor::setSpeed(int speed){
    speed = speed;
}

void Motor::setMaxLimit(int max){
    _max_limit = max;
}

void Motor::setMinLimit(int min){
    _min_limit = min;
}

void Motor::move(int deg){
    int current_deg = current();
    if (current_deg > deg + 2 ){
        while(current_deg > deg + 2 && current_deg > _min_limit ) {
            if (direction == 1){
                digitalWrite(en, speed);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            } else if (direction == -1){
                digitalWrite(en, speed);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            }
            current_deg = current();
        }
        stopMotor();
    } else if (current_deg < deg - 2){
        while(current_def < deg - 2 && current_def < _max_limit) {
            if (direction == 1){
                digitalWrite(en, speed);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            } else if (direction == -1){
                digitalWrite(en, speed);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            }
            current_deg = current();
        }
    } else {
        stopMotor();
    }
}



// HAND SET UP ===================================================================================================

Hand::Hand(int thumb, int index, int middle, int ring, int pinky, int wrist){

    thumb.attach(thumb);
    index.attach(index);
    middle.attach(middle);
    ring.attach(ring);
    pinky.attach(pinky);
    wrist.attach(wrist);
    
}

void Hand::open(){
    thumb.write(0);
    index.write(0); 
    middle.write(0);
    ring.write(0);
    pinky.write(0);
}

void  Hand::close(){
    thumb.write(270);
    index.write(270);
    middle.write(270);
    ring.write(270);
    pinky.write(270);
}

void Hand::finger_moving(string finger){
    if (finger == "thumb"){
        int count = 0;
        while(count < 3){
            thumb.write(0);
            delay(500);
            thumb.write(180);
            delay(500);
            count++;
        }
    } else if (finger == "index"){
        int count = 0;
        while(count < 3){
            index.write(0);
            delay(500);
            index.write(180);
            delay(500);
            count++;
        }
    } else if (finger == "middle"){
        int count = 0;
        while(count < 3){
            middle.write(0);
            delay(500);
            middle.write(180);
            delay(500);
            count++;
        }
    } else if (finger == "ring"){
        int count = 0;
        while(count < 3){
            ring.write(0);
            delay(500);
            ring.write(180);
            delay(500);
            count++;
        }
    } else if(finger == "pinky"){
        int count = 0;
        while(count < 3){
            pinky.write(0);
            delay(500);
            pinky.write(180);
            delay(500);
            count++;
        }
    }

}

void Hand::wrist(int degree){
    wrist.write(degree);
}

// SHIELD MOTOR  CONTROL FUNCTIONS //////////////////////////////////////////////////////////////////////////
Shield_Motor::Shield_Motor(int dc_motor, int potPin){
    _dc_motor = dc_motor;
    _potPin = potPin;
    dcMotor = AF_DCMotor(_dc_motor);
}

void Shield_Motor::setDirection(int direct){
    _direction = direct;
}

void  Shield_Motor::setSpeed(int speed){
    _speed = speed;
    dcMotor.setSpeed(_speed) ;  
}

int Shield_Motor::current(){
    _current = map(analogRead(_potPin), 0, 1023, 0, 270);  
    return _current;
}

void Shield_Motor::setMinLimit(int min){
    _min_limit = min;
}

void Shield_Motor::setMaxLimit(int max){
    _max_limit = max;
}

void Shield_Motor::move(int deg){
    int current_deg = current();
    if (current_deg > deg + _delta && current_deg > _min_limit) {
        while(current_deg > deg + _delta ) {
            if (direction == 1){
                dcMotor.run(FORWARD);
            } else if (direction == -1){
                dcMotor.run(BACKWARD);
            }
            current_deg = current();
        }
        dcMotor.run(RELEASE);
    } else if (current_deg < deg - _delta){
        while(current_deg < deg - _delta && current_deg < _max_limit){
            if (direction == 1){
                dcMotor.run(BACKWARD);
            } else if (direction == -1){
                dcMotor.run(FORWARD);
            }
            current_deg  = current();
        }
        dcMotor.run(RELEASE);
    } else {
        dcMotor.run(RELEASE); 
    }
}

// HEAD SET UP ===============================================================================================
Head::Head(int side_eye, int mouth, int up_eye, int head, int neck, int side_neck){
    side_eye.attach(side_eye);
    mouth.attach(mouth);
    up_eye.attach(up_eye);
    neck.attach(neck);
    head.attach(head);
    side_neck.attach(side_neck);
}

void Head::head(int degree){
    // ... - ... is turn left 
    // ... - ... is turn right 
    // ... is center
    head.write(degree);  
}

void Head::neck(int degree){
    // ... - ...  is up 
    // ... - ... is down 
    // ... is center
    neck.write(degree);
}

void Head::mouth(int degree) {
    // ... - ... is open
    // ... - ... is close
    mouth.write(degree);
}

void Head::side_eye(int degree){
    // ... - ... is left
    // ... - ... is right
    // ... is center
    side_eye.write(degree);
}

void Head::setMaxLimit(int max){
    _max_limit = max;
}

void Head::setMinLimit(int min){
    _min_limit  = min;
}

void Head::up_eye(int degree){
    // ... - ... is up 
    // ... - ... is down 
    // ... is center 
    up_eye.write(degree);
}

void Head::neck_side(int degree){
    // ... - ... is left tilt
    // ... - ... is right tilt 
    // ... is center
    side_neck.write(degree);
}

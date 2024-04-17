#include "agiat_library.h"

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

int Motor::current_deg(){
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

void Motor::set_speed(int velocity){
    _velocity = velocity;
}

void Motor::setMaxLimit(int max_){
    _max_limit = max_;
}

void Motor::setMinLimit(int min_){
    _min_limit = min_;
}

void Motor::move_motor(int deg){
    int current_degree = current_deg();
    if (current_degree > deg + 2 ){
        while(current_degree > deg + 2 && current_degree > _min_limit ) {
            if (_direction == 1){
                digitalWrite(en, _velocity);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            } else if (_direction == -1){
                digitalWrite(en, _velocity);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            }
            current_degree = current_deg();
        }
        stopMotor();
    } else if (current_degree < deg - 2){
        while(current_degree < deg - 2 && current_degree < _max_limit) {
            if (_direction == 1){
                digitalWrite(en, _velocity);
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
            } else if (_direction == -1){
                digitalWrite(en, _velocity);
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
            }
            current_degree = current_deg();
        }
    } else {
        stopMotor();
    }
}



// HAND SET UP ===================================================================================================

Hand::Hand(int th, int ind, int mid, int rin, int pink, int wri){

    thumb.attach(th);
    index.attach(ind);
    middle.attach(mid);
    ring.attach(rin);
    pinky.attach(pink);
    wrist.attach(wri);
    
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

void Hand::finger_moving(String finger){
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

void Hand::servo_wrist(int degree){
    wrist.write(degree);
}

// SHIELD MOTOR  CONTROL FUNCTIONS //////////////////////////////////////////////////////////////////////////
Shield_Motor::Shield_Motor(int potPin) {
    _potPin = potPin;
}

void Shield_Motor::setDirection(int direct){
    _direction = direct;
}

int Shield_Motor::current_deg(){
    _current = map(analogRead(_potPin), 0, 1023, 0, 270);  
    return _current;
}

void Shield_Motor::setMinLimit(int min_){
    _min_limit = min_;
}

void Shield_Motor::setMaxLimit(int max_){
    _max_limit = max_;
}

int Shield_Motor::get_dir(){
  return _direction;
}

void Shield_Motor::move_motor(AF_DCMotor dcMotor, int deg){
    int current_degree = current_deg();
    if (current_degree > deg + _delta ) {
        while(current_degree > deg + _delta ) {
            if (_direction == 1){
                dcMotor.run(FORWARD);
            } else if (_direction == -1){
                dcMotor.run(BACKWARD);
            }
            current_degree = current_deg();
        }
        dcMotor.run(RELEASE);
    } else if (current_degree < deg - _delta  ){
        while(current_degree < deg - _delta ){
            if (_direction == 1){
                dcMotor.run(BACKWARD);
            } else if (_direction == -1){
                dcMotor.run(FORWARD);
            }
            current_degree  = current_deg();
        }
        dcMotor.run(RELEASE);
    } else {
        dcMotor.run(RELEASE); 
    }
}

// HEAD SET UP ===============================================================================================
Head::Head(int se, int m, int ue, int h, int n, int sn){
    side_eye.attach(se);
    mouth.attach(m);
    up_eye.attach(ue);
    neck.attach(n);
    head.attach(h);
    side_neck.attach(sn);
}

void Head::servo_head(int degree){
    // ... - ... is turn left 
    // ... - ... is turn right 
    // ... is center
    head.write(degree);  
}

void Head::servo_neck(int degree){
    // ... - ...  is up 
    // ... - ... is down 
    // ... is center
    neck.write(degree);
}

void Head::servo_mouth(int degree) {
    // ... - ... is open
    // ... - ... is close
    mouth.write(degree);
}

void Head::servo_side_eye(int degree){
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

void Head::servo_up_eye(int degree){
    // ... - ... is up 
    // ... - ... is down 
    // ... is center 
    up_eye.write(degree);
}

void Head::servo_side_neck(int degree){
    // ... - ... is left tilt
    // ... - ... is right tilt 
    // ... is center
    side_neck.write(degree);
}

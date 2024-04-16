#include "motor_drive.h"

Shield_Motor::Shield_Motor(uint8_t motorNum, int potPin) : dcMotor(motorNum, MOTOR12_8KHZ) {
    _potPin = potPin;
}

void Shield_Motor::setDirection(int direct){
    _direction = direct;
}

void  Shield_Motor::set_speed(int velocity){
    dcMotor.setSpeed(velocity) ;  
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

void Shield_Motor::stopMotor(){
    dcMotor.run(RELEASE);
}

void Shield_Motor::move_motor(int deg){
    int current_degree = current_deg();
    if (current_degree > deg + _delta && current_degree > _min_limit) {
        while(current_degree > deg + _delta ) {
            if (_direction == 1){
                dcMotor.run(FORWARD);
            } else if (_direction == -1){
                dcMotor.run(BACKWARD);
            }
            current_degree = current_deg();
        }
        dcMotor.run(RELEASE);
    } else if (current_degree < deg - _delta && current_degree < _max_limit ){
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

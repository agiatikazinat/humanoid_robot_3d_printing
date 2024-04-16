#ifndef MOTOR_DRIVE_h
#define MOTOR_DRIVE_h

#include <Arduino.h>
#include <AFMotor.h>


class Shield_Motor{
    private:
        AF_DCMotor dcMotor;
        int _direction = 1;
        int _potPin;
        int _delta = 2;
        int _current;
        int _min_limit, _max_limit;

    public:
        Shield_Motor(uint8_t motorNum, int potPin);
        void move_motor(int degree);
        void setDirection(int direct);
        void set_speed(int velocity);
        int current_deg();
        void setMinLimit(int min_);
        void setMaxLimit(int max_);
        void stopMotor();

};

#endif

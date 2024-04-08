#ifndef LIBRARY_H
#define LIBRARY_H 

#include <Arduino.h>
#include <Servo.h>
#include "library.cpp"

class Motor{
    private:
        int en;
        int in1;
        int in2;
        int potPin;
        int current;
        int speed;
        int const delta = 2;
        int _direction = 1;
        int _min_limit, _max_limit;

    public:
        Motor(int en, int in1, int in2, int potPin);
        int current_deg();
        void move(int degree);
        void setSpeed(int speed);
        void stopMotor();
        void setDirection(int direct);
        void setMinLimit(int min);
        void setMaxLimit(int max);
};

class Shield_Motor{
    private:
        int _dc_motor;
        AF_DCMotor dcMotor;
        int _direction = 1;
        int _potPin;
        int _delta = 2;
        int _current;
        int _speed;
        int _min_limit, _max_limit;

    public:
        Shield_Motor(int dc_motor, int potPin);
        void move(int degree);
        void setDirection(int direct);
        void setSpeed(int  speed);
        int current();
        void setMinLimit(int min);
        void setMaxLimit(int max);
        void stopMotor();

};

class Hand{
    private:
        Servo thumb, index, middle, ring, pinky, wrist; 
        int const delta;
        int direction = 1;

    public:
        Hand(int thumb, int index, int middle, int ring, int pinky, int wrist);
        void open();
        void close();
        void finger_moving(String finger);
        void servo_wrist(int degree);
};

class Head{
    private:
        int _min_limit, _max_limit;
    public:
        Servo side_eye, mouth, up_eye, head, neck, side_neck;

        Head(int side_eye, int mouth, int up_eye, int head, int  neck, int side_neck);
        void servo_head(int degree);
        void servo_mouth(int degree);
        void servo_side_eye(int degree);
        void servo_up_eye(int degree);
        void servo_side_neck(int degree);
        void servo_neck(int degree);
        void setMaxLimit(int max);
        void setMinLimit(int min);

};





#endif
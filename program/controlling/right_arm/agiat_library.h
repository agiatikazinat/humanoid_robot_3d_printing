#ifndef AGIAT_LIBRARY_h
#define AGIAT_LIBRARY_h 

#include <Arduino.h>
#include <Servo.h>
#include <AFMotor.h>

class Motor{
    private:
        int en;
        int in1;
        int in2;
        int potPin;
        int current;
        int _velocity;
        int const delta = 2;
        int _direction = 1;
        int _min_limit, _max_limit;

    public:
        Motor(int en, int in1, int in2, int potPin);
        int current_deg();
        void move_motor(int degree);
        void set_speed(int velocity);
        void stopMotor();
        void setDirection(int direct);
        void setMinLimit(int min_);
        void setMaxLimit(int max_);
};

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

class Hand{
    private:
        Servo thumb, index, middle, ring, pinky, wrist; 
        int const delta;
        int direction = 1;

    public:
        Hand(int th, int ind, int mid, int rin, int pink, int wri);
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

        Head(int se, int m, int ue, int h, int n, int sn);
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

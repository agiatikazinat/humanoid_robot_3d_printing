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

    public:
        Motor(int en, int in1, int in2, int potPin);
        int current();
        void move(int degree);
        void setSpeed(int speed);
        void stopMotor();
        void setDirection(int direct);
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

    public:
        Shield_Motor(int dc_motor, int potPin);
        void move(int degree);
        void setDirection(int direct);
        void setSpeed(int  speed);
        int current();
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
        void finger_moving(string finger);
        void wrist(int degree);
};

class Head{
    private:
        Servo side_eye, mouth, up_eye, head, neck, side_neck;
    public:
        Head(int side_eye, int mouth, int up_eye, int head, int  neck, int side_neck);
        void head(int degree);
        void mouth(int degree);
        void side_eye(int degree);
        void up_eye(int degree);
        void neck_side(int degree);
        void neck(int degree);

}



#endif
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
        int direction = 1;

    public:
        Motor(int en, int in1, int in2, int potPin);
        int current();
        void move(int degree);
        void setSpeed(int speed);
        void stopMotor();
};

class Hand{
    private:
        int thumb;
        int index;
        int middle;
        int ring;
        int pinky;
        int wrist;
        int const delta;
        int direction = 1;

    public:
        Hand(int thumb, int index, int middle, int ring, int pinky, int wrist);
        void open();
        void close();
        void finger_moving(string finger);
        void wrist(int degree);
};




#endif
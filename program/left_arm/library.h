#ifndef LIBRARY_H
#define LIBRARY_H 

#include <Arduino.h>
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
}




#endif
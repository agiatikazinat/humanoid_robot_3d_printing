#include <Servo.h>

long previousMillis1 = 0;
long previousMillis2 = 0;
long interval1 = 1000;
long interval2 = 500;

    int num1 = 0;
    int num2 = 0;


Servo motor;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
motor.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

  long currentMillis = millis();

  if (Serial.available() > 0) {
    char input = Serial.read(); // read the incoming byte

    num1 = 0;
    num2 = 0;

    if (currentMillis - previousMillis1 >= interval1 && num1 < 10000 && input == '1') {
      function1();
      previousMillis1 = currentMillis;
      Serial.print("DONE 1: ");
      Serial.println(num1);
    }

    if (currentMillis - previousMillis2 >= interval2 && num2 < 10100 && input == '2'){
      function2();
      previousMillis2 = currentMillis;
      Serial.print("DONE 2: ");
      Serial.println(num2);
    }

  }

}

void function1(){
  while (num1 < 1000){
    num1++;

  }
  motor.write(180);
  Serial.println("DONE");
}

void function2(){
  while(num2 < 1010){
    num2++;
  }
}
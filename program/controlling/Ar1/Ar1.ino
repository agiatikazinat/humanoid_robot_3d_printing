#include <Servo.h>
#include "~/Document/Agiat_Ikazinat/program/controlling/library/library.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Hand left_hand(40, 41, 44, 45, 43, 42);
  Hand right_hand(34, 33, 32, 31, 30, 29);
  Head head(28, 27, 37, 36, 39, 38);
}

void loop() {
  // put your main code here, to run repeatedly:

}

#include <Servo.h>
#include "/home/ikazinatagiat/Documents/Agiat_Ikazinat/program/controlling/library/library.h"

Hand left_hand(40, 41, 44, 45, 43, 42);
Hand right_hand(34, 33, 32, 31, 30, 29);
Head head(28, 27, 37, 36, 39, 38);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    // get the command from controlling program 
    String command = Serial.readStringUntil('\n');
    
    // split the command
    StringSplitter *splitter = new StringSplitter(command, ' ');

    int itemCount = splitter->getItemCount();

    String motorName = splitter->getItemAtIndex(0);
    String method = splitter->getItemAtIndex(1);
    String param;

    if (itemCount == 3){
      param = splitter->getItemAtIndex(2); 
    }


    // FOR LEFT HAND ============================================================
    if ( motorName == "left_hand" && method == "open"){
      left_hand.open();
    } 
    else if (motorName == "left_hand" && method == "close"){
      left_hand.close();
    }
    else if (motorName == "left_hand" && method == "finger_moving"){
      left_hand.finger_move(param);
    }
    else if (motorName == "left_hand" && method == "wrist"){
      left_hand.wrist(param.toInt());
    }

    // FOR RIGHT HAND ============================================================
    if ( motorName == "right_hand" && method == "open"){
      right_hand.open();
    } 
    else if (motorName == "right_hand" && method == "close"){
      right_hand.close();
    }
    else if (motorName == "right_hand" && method == "finger_moving"){
      right_hand.finger_move(param);
    }
    else if (motorName == "right_hand" && method == "wrist"){
      right_hand.wrist(param.toInt());
    }

    // FOR HEAD ==================================================================
    if (motorName == "head" && method == "head"){
      head.head(param.toInt());
    }
    else if (motorName == "head" && method == "mouth"){
      head.mouth(param.toInt());
    }
    else if (motorName == "head" && method == "side_eye"){
      head.side_eye(param.toInt());
    }
    else if (motorName == "head" && method == "up_eye"){
      head.up_eye(param.toInt());
    }
    else if (motorName == "head" && method == "neck_side"){
      head.neck_side(param.toInt());
    }
    else if (motorName == "head" && method == "neck"){
      head.neck(param.toInt());
    }

  }
}

long previousMillis1 = 0;
long previousMillis2 = 0;
long interval1 = 1000;
long interval2 = 100;

int num1 = 0;
int num2 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  long currentMillis = millis();

  if (currentMillis - previousMillis1 >= interval1 && num1 < 100) {
    function1();
    previousMillis1 = currentMillis;
    Serial.print("DONE 1: ");
    Serial.println(num1);
  }

  if (currentMillis - previousMillis2 >= interval2 && num2 < 100){
    function2();
    previousMillis2 = currentMillis;
    Serial.print("DONE 2: ");
    Serial.println(num2);
  }

}

void function1(){
  while (num1 < 100){
    num1++;
  }
}

void function2(){
  while(num2 < 100){
    num2++;
  }
}
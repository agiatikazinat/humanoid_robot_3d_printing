
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String command = Serial.readStringUntil('\n');
    if (command == "on"){
      digitalWrite(13, HIGH);
      //Serial.println("LED turned on");
    } else if (command == "off"){
      digitalWrite(13, LOW);
      //count--;
      //Serial.println("LED turned OFF");
    }
    //Serial.println(count);
    Serial.println("Finish");
  }
}

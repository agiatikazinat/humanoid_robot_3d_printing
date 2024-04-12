const int potPin = A0; //pin A0 to read analog input

//Variables:
int value; //save analog value


void setup(){
  //Input or output?
  Serial.begin(9600);
  pinMode(potPin, INPUT); //Optional 

}

void loop(){
  
  value = analogRead(potPin);          //Read and save analog value from potentiometer
  value = map(value, 0, 1023, 0, 270); //Map value 0-1023 to 0-255 (PWM)
  Serial.println(value);
  delay(100);                          //Small delay
  
}
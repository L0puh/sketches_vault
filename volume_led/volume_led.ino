int led = 3;
void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  if (Serial.available() > 0){

    int volume = Serial.parseInt();
    int brightness = volume % 255;
    analogWrite(led, brightness);
    delay(20);
  }
  else {
    analogWrite(led, 10);
  }

}

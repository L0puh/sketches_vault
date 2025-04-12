const int analog = A0; 
const int led = 9;
 
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void get_analog(){
  Serial.print("analog: ");
  Serial.println(analogRead(analog)); 
  if (analogRead(analog) > 27){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
  }
  delay(50);
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

int buzzer = 11;
int button = 2;
int red_led = 6;
int green_led = 7;
int detector =  4;
void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(detector, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop(){

  Serial.println(digitalRead(detector));
  while (digitalRead(button)){
      analogWrite(buzzer, 30);
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
  }
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, HIGH);
  digitalWrite(buzzer,LOW);
  delay(1);
}

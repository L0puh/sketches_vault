int button = 13;
int number = 1;

void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(button, INPUT);
}


void loop() {
   int i = 1000; 
 
   int state = digitalRead(button);
   if (state){
     write_num(number++);
     if (number >= 10)
       number = 1;
   } else {
     clear();
   }
}

void write_num(int num){
  switch(num){
    case 1:
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      break;

    case 2:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
           
    case 3:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      break;
    
    case 4:
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      break;

    case 5:
      digitalWrite(2, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 6:
      digitalWrite(2, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 7:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      break;
    case 8:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
    case 9:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);

      break;
  }
}
void clear(){
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
}

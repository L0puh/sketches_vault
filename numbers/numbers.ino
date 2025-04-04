int button = 13;
int number = 0;
bool turn_on = true;
void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(button, INPUT);
}


void loop() {
   int i = 10; 

   if (turn_on){
     if (Serial.available() > 0){
       int num = Serial.parseInt();
       if (num) number = num;
       clear();
     }
     write_num(number);
   } else {
     clear();
   }
   int state = digitalRead(button);
   if (state) {
     delay(40);
     turn_on = !turn_on;
   }
 
}

void write_num(int num){
  switch(num){
    case 1:
      digitalWrite(10, HIGH);
      digitalWrite(5, HIGH);
      break;

    case 2:
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      break;
           
    case 3:
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
      break;
    
    case 4:
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      break;

    case 5:
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      break;
    case 6:
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      break;
    case 7:
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 8:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      break;
    case 9:

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      break;
    case 0:

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);

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
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
}

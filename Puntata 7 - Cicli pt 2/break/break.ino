#define LEDBLUE 3
#define LEDGREEN 2
#define BUTTON_1 12
#define BUTTON_2 11

bool statusBLUE = false;
bool statusGREEN = false;

void setup() {
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);  
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
}

void loop() {
  while(1) {
    statusBLUE = !statusBLUE;
    digitalWrite(LEDBLUE, statusBLUE);
    if(digitalRead(BUTTON_1) == LOW) {
      digitalWrite(LEDBLUE, LOW);
      break;   
    }  
    delay(100);
  }
  while(1) {
    statusGREEN = !statusGREEN;
    digitalWrite(LEDGREEN, statusGREEN);
    if(digitalRead(BUTTON_2) == LOW) {
      digitalWrite(LEDGREEN, LOW);
      break;   
    }  
    delay(100);
  }  
}

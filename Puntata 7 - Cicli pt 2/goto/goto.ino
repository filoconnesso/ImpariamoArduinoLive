#define LEDBLUE 3
#define LEDGREEN 2
#define BUTTON_1 12
#define BUTTON_2 11

bool statusBLUE = false;
bool statusGREEN = false;
bool statusSTART = false;

void setup() {

  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

}

void loop() {

  if(!statusSTART) {
    statusSTART = true;
    goto blinkblue;
  }  

  blinkblue :
    while(1) {
      statusBLUE = !statusBLUE;
      digitalWrite(LEDGREEN, LOW);  
      digitalWrite(LEDBLUE, statusBLUE);
      delay(300);
      if(digitalRead(BUTTON_1) == LOW) {      
        goto blinkgreen;
      }
    }
  
  blinkgreen :
    while(1) {
      statusGREEN = !statusGREEN;
      digitalWrite(LEDBLUE, LOW);
      digitalWrite(LEDGREEN, statusGREEN);
      delay(300);
      if(digitalRead(BUTTON_2) == LOW) {
        goto blinkblue;
      }
    }

}

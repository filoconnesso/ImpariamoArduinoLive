#define LEDBLUE 2
#define LEDGREEN 3
#define LEDRED 4
#define LEDWHITE 5
#define LEDYELLOW 6

#define BUTTON_1 12

int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};

void setup() {

  pinMode(BUTTON_1, INPUT_PULLUP);

  for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  
  while(digitalRead(BUTTON_1) == HIGH) {
    for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
      digitalWrite(pins[i], HIGH);
      delay(50);
    }
    for(int i = (sizeof(pins) / sizeof(pins[0])); i >= 0 ; i--) {
      digitalWrite(pins[i], LOW);
      delay(50);
    }
  }
  
  for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
      digitalWrite(pins[i], LOW);
  }

}

void loop() {
  for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
      digitalWrite(pins[i], HIGH);
  }
  delay(500);
  for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
      digitalWrite(pins[i], LOW);
  }
  delay(500);
}

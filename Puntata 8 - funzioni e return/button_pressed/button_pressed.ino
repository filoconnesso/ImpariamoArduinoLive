void pressed(int pin, void (*func)(int), int exitpin) {
  if(digitalRead(pin) == LOW) {
    func(exitpin);
  }
}

void ledon(int pin) {
  digitalWrite(pin, HIGH);
}
void ledoff(int pin) {
  digitalWrite(pin, LOW);
}

void setup() {
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

void loop() {
  pressed(12, ledon, 2);
  pressed(11, ledoff, 2);
}

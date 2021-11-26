void printer(String word) {
  Serial.println(word);
}

void toPrint(void (*func)(String), String word) {
  func(word);
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  toPrint(printer, "pippo");
  printer("pippo");
}

void loop() {

}

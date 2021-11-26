void counter(int start, int finish) {
  int counter = start;
  while(counter <= finish) {
    Serial.println(counter);
    counter++;
  }
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  counter(30, 100);
}

void loop() {
  

}

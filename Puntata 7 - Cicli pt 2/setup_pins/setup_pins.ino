#define LEDBLUE 2
#define LEDGREEN 3
#define LEDRED 4
#define LEDWHITE 5
#define LEDYELLOW 6

int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};
bool status[] = {LOW, LOW, LOW, LOW, LOW};

void setup() {

  Serial.begin(115200);
  while(!Serial);
  
  for(int i = 0; i <= (sizeof(pins) / sizeof(pins[0])); i++) {
    status[i] = !status[i];
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], status[i]);
    delay(300);
  }

  Serial.print("Pin counter : ");
  Serial.print((sizeof(pins) / sizeof(pins[0])));
  Serial.println();

}

void loop() {
  
}

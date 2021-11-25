#define LEDBLUE 2
#define LEDGREEN 3
#define LEDRED 4
#define LEDWHITE 5
#define LEDYELLOW 6

int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};

void setup() {

  Serial.begin(115200);
  while(!Serial);
  
  for(auto pin : pins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(300);
  }

}

void loop() {
  
}

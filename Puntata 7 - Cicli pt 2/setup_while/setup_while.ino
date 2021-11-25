#define LEDBLUE 2

bool statusBLUE = false;
int counter = 0;

void setup() {

  Serial.begin(9600);
  while(!Serial);

  Serial.println("SETUP");

  pinMode(LEDBLUE, OUTPUT);

  while(counter <= 10) {
    statusBLUE = !statusBLUE;
    Serial.print("led : ");
    Serial.print(statusBLUE);
    Serial.println();
    digitalWrite(LEDBLUE, statusBLUE);
    counter++;
    delay(1000);
  }

}

void loop() {
  Serial.println("LOOP");
}

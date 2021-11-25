#define LEDBLUE 3
#define BUTTON_1 12

bool statusBLUE = false;
int statusBUTTON;

void setup() {

 Serial.begin(115200);

 pinMode(LEDBLUE, OUTPUT);
 pinMode(BUTTON_1, INPUT_PULLUP);

 do {
   statusBLUE = !statusBLUE; 
   statusBUTTON = digitalRead(BUTTON_1);
   Serial.println(statusBUTTON);
   digitalWrite(LEDBLUE, statusBLUE);
   delay(100);
 } while (statusBUTTON == HIGH);

}

void loop() {
 Serial.println("loop");
}

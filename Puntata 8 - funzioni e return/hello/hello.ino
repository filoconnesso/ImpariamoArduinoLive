String hello(String yourName) {
  return "Ciao, " + yourName;
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println(hello("pippo"));
}

void loop() {
  

}

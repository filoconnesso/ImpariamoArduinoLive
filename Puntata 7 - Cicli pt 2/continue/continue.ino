void setup() {
  
  Serial.begin(115200);
  while(!Serial);

  int x = 0;
  while(x < 9) {
    x++;
    if(x == 5) {
      continue;   
    }  
    Serial.println(x);
  }

}

void loop() {
  

}

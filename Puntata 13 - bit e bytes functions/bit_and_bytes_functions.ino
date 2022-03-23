

void setup() {
  //Apro la seriale
  Serial.begin(9600);
  //Aspetto che venga aperto il monitor seriale
  while(!Serial);
  
  //Creo una variabile byte con valore 150
  byte x = 150; //byte è formato da 8 bit e il suo valore può assumere un valore da 0 a 255
  
  //bitRead è una funzione che permette di leggere un bit specifico di una variabile
  //Metodo di lettura usato in questo caso è MSB (MOST SIGNIFICANT BIT), quindi si legge dal bit più significativo
  //Altro metodo di lettura è LSB (LEAST SIGNIFICANT BIT) usato per i decimali
  
  Serial.print(bitRead(x, 7)); //posizione più significativa
  Serial.print(bitRead(x, 6));
  Serial.print(bitRead(x, 5));
  Serial.print(bitRead(x, 4));
  Serial.print(bitRead(x, 3));
  Serial.print(bitRead(x, 2));
  Serial.print(bitRead(x, 1));
  Serial.print(bitRead(x, 0)); //posizione meno significativa
  Serial.println();
  
  //il seguente for effettua la stessa operazione dei Serial.print() precedenti ma usa l'operatore >> (bitwise right) dei bitwise
  for(uint8_t i = 8; i > 0; --i){
    Serial.print((x >> i - 1) & 1);
  }

  Serial.println();
  //bitSet setta 1 un bit a scelta di una variabile
  //Creo una variabile byte con valore 120
  byte u = 120; 
  //Stampo il valore attuale della variabile 
  Serial.println(u);
  Serial.println(u, BIN); //1111000
  //Setto a 1 il bit 7
  bitSet(u, 7);
  //Setto a 1 il bit 6
  bitSet(u, 6);
  //Setto a 1 il bit 5
  bitSet(u, 5);
  //Setto a 1 il bit 4
  bitSet(u, 4);
  //Setto a 1 il bit 3
  bitSet(u, 3);
  //Setto a 1 il bit 2
  bitSet(u, 2);
  //Setto a 1 il bit 1
  bitSet(u, 1);
  //Setto a 1 il bit 0
  bitSet(u, 0);
  //Stampo il nuovo valore di u = 255
  Serial.println(u); //255
  //Stampo il valore in binario di u (255)
  Serial.println(u, BIN); //11111111

  //bitClear permette di settare a 0 un bit a scelta di una variabile
  //Setto a 0 il bit 7
  bitClear(u, 7);
   //Setto a 0 il bit 6
  bitClear(u, 6);
   //Setto a 0 il bit 5
  bitClear(u, 5);
   //Setto a 0 il bit 4
  bitClear(u, 4);
   //Setto a 0 il bit 3
  bitClear(u, 3);
   //Setto a 0 il bit 2
  bitClear(u, 2);
   //Setto a 0 il bit 1
  bitClear(u, 1);
   //Setto a 0 il bit 0
  bitClear(u, 0);
  //Stampo il nuovo valore di u = 0
  Serial.println(u);
  //Stampo il valore in binario di u (0)
  Serial.println(u, BIN); //00000000
  
  //bitWrite permette di settare un bit con un valore a scelta (1 o 0)
  //Setto a 1 il bit 7
  bitWrite(u, 7, 1);
  //Setto a 0 il bit 6
  bitWrite(u, 6, 0);
  //Setto a 1 il bit 5
  bitWrite(u, 5, 1);
  //Setto a 0 il bit 4
  bitWrite(u, 4, 0);
  //Setto a 0 il bit 3
  bitWrite(u, 3, 0);
  //Setto a 0 il bit 2
  bitWrite(u, 2, 0);
  //Setto a 0 il bit 1
  bitWrite(u, 1, 0);
  //Setto a 0 il bit 0
  bitWrite(u, 0, 0);
  //Stampo il nuovo valore di u = 160
  Serial.println(u);
  //Stampo il valore in binario di u (0)
  Serial.println(u, BIN); //10100000

}

void loop() {
  // put your main code here, to run repeatedly:

}

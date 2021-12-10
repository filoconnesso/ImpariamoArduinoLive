/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 11 di Impariamo Arduino Live : https://www.youtube.com/watch?v=JXEx49cuLww
* Esempi pratici sui converitori di Char
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/
//Creo una variabile char semplice con il valore "A"
char lettera = 'A';
//Creo un array di char con il valore "test"
char frase[] = "test";
//Creo un array di char con il valore ascii della parola "filoconnesso"
char fraseascii[] = {102,105,108,111,99,111,110,110,101,115,115,111,0};
//Creo una variabile int con il valore ascii della variabile char "lettera"
int numero = int(lettera);
//Creo una variabile int con il valore 12
int numero1 = 12;
//Creo una variabile intera con il valore "1000"
int numero2 = 1000;
//Creo una variabile long con il valore convertito in long della variabile numero2
int numero3 = 1000;

//Creo due variabili unsigned long
unsigned long currentmillis, previousmillis;

//Creo una variabile unsigned int con valore 10
int numero4 = 10;

void setup() {
  //Apro la seriale
  Serial.begin(9600);
  //Aspetto che venga aperto Il Monitor Seriale
  while(!Serial);
  //Stampo il valore della variabile numero
  Serial.println(numero);
  //Stampo con un ciclo for tutti i char all'interno dell'array char "frase"
  for(int i = 0; i < 5; i++) {
    Serial.print(frase[i]);
    Serial.print(" ");
  }
  //Stampo con un ciclo for tutti i char convertiti in int (valore ascii) dell'array char "frase"
  for(int i = 0; i < 4; i++) {
    Serial.print(int(frase[i]));
    Serial.print(" ");
  }
  Serial.println();
  //Stampo tutti i valori convertiti in char dell'array char "frasescii"
  for(int i = 0; i < 12; i++) {
    Serial.print(char(fraseascii[i]));
  }
  Serial.println();
  //Converto e stampo il valore della variabile intera numero1 in float
  Serial.print((float)numero1);
  Serial.println();
  //Stampo il valore long della variabile numero3
  Serial.print(numero3);
  Serial.println();
  //Stampo il valore della variabile intera "numero4" convertita in unsigned int
  Serial.print((unsigned int)numero4); 
  Serial.println();
  //Assegno il valore corrente dei millis a previousmillis
  previousmillis = millis();
 
}

void loop() {
  //Assegno di continuo il valore corrente dei millis a currentmillis
  currentmillis = millis();

  //controllo che la differenza tra currentmillis e previousmillis è maggiore della variabile long in unsigned long
  //oltretutto converto anche la condizione totale in unsigned long per garantirmi un risultato della differenza sempre di tipo unsigned long
  //ogni secondo verranno stampati i millis sul monitor seriale
  if((unsigned long)currentmillis - previousmillis > (unsigned long)numero3) {
    //Stampo millis
    Serial.println(currentmillis);
    //aggiorno il valore di previousmillis con il valore corrente dei millis, questo permette di mantenere traccia del tempo passato tra un controllo e l'altro
    previousmillis = currentmillis;
  }
  

}

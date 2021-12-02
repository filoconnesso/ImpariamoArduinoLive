/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 9 di Impariamo Arduino Live : https://www.youtube.com/watch?v=aUWFLuYPivI
* Confronto di dimensioni tra array di char e String
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//inizializzo due variabili con lo stesso valore, una variabile è di tipo String e una di tipo array char

String stringa1 = "stringa"; //inizializzo una String con valore "stringa"
char stringa2[] = "stringa"; //inizializzo un array di char con valore "stringa"

void setup() {
  //avvio la seriale con baudrate 9600, ricordati di inserire lo stesso baudrate nel Monitor Seriale
  Serial.begin(9600);
  //attendo che venga aperto il Monitor seriale per continuare il programma
  while(!Serial);
  
  //Stampo il valore della variabile di tipo String (stringa1)
  Serial.println(stringa1);
  //Stampo il numero di byte di stringa1
  Serial.print(sizeof(stringa1));
  Serial.println(F("byte")); //rendo statico il valore della stringa byte in modo tale da occupare meno memoria dinamica
  
  //Stampo il valore della variabile di tipo array char (stringa2)
  Serial.println(stringa2);
  //Stampo il numero di byte di stringa 2
  Serial.print(sizeof(stringa2));
  Serial.println(F("byte")); //rendo statico il valore della stringa byte in modo tale da occupare meno memoria dinamica

  //ovviamente la variabile di tipo String occuperà più byte rispetto all'array di char
  //questo accade perchè String è una classe con i suoi metodi e non una vera e propria variabile

}

void loop() {
  

}

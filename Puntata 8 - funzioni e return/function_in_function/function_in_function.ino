/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 8 di Impariamo Arduino Live : https://youtu.be/nKjv-KkZZig
* La funzione mostrata nell'esempio permette di richiamare un'altra funzione durante l'esecuzione del codice
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//creo la funzione "printer" che ha un argomento String
//l'argomento "word" ci permette di indicare la parola o la frase che dovrà stampare l'istruzione Serial.println
void printer(String word) {
  //Serial.println(word) stamperà sulla seriale il valore che impostiamo nell'argomento word di "printer"
  //richiamando printer("ciao"); è come se avessimo scritto Serial.println("ciao");
  //questo metodo di "incapsulamento" si chiama wrapping
  Serial.println(word);
}

//creo la funzione "toPrint" che permetterà nel corso del codice di richiamare la funzione "printer"
//la funzione "toPrint" ha due argomenti, il primo di tipo void chiamato "func" e il secondo di tipo String
//l'argomento void "func" a sua volta ha un argomento String, visto che sappiamo già che andremo a richiamare la funzione "printer"
//l'argomento word ci permetterà di settare la stringa da far stampare a printer
void toPrint(void (*func)(String), String word) {
  //in questo caso ad ogni chiamata di toPrint, chiamerò la funzione "printer" e gli darò un valore da stampare (con l'argomento word)
  func(word);
}

void setup() {
  //avvio la seriale con baudrate 9600, ricordati di settarlo anche nel tuo Monitor Seriale
  Serial.begin(9600);
  //attendo affinchè il Monitor Seriale non venga aperto con un ciclo while che controlla che Serial vada a true
  while(!Serial);
  //richiamando toPrint(printer, "pippo"); o printer("pippo"); eseguiremo la stessa operazione
  //entrambi le operazioni scrivono la parola "pippo" sulla seriale 
  //in entrambi i casi usiamo la funzione "printer" per stampare in seriale
  toPrint(printer, "pippo");
  printer("pippo");

  //il programma finisce qui ed entra nel loop
  //per eseguire di nuovo le operazioni del programma chiudi il Monitor Seriale, riavvia la board e riapri il Monitor Seriale
}

void loop() {

}

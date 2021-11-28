/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 8 di Impariamo Arduino Live : https://youtu.be/nKjv-KkZZig
* L'esempio permette di richiamare un while che stampa i tutti i valori da uno valore di inizio e un valore di fine
* nell'esempio usiamo i valori tra 30 e 100, ma potete personalizzarli
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//creo una funzione chiamata "counter" la quale ha due argomenti di tipo int
//il primo argomento "start" ci permette di indicare un valore di inizio
//il secondo argomento "finish" ci permette di indicare un valore di fine
void counter(int start, int finish) {
  //creo una variabile int chiamata "counter" che utilizzeremo per tenere traccia del valore attuale all'interno del ciclo
  //alla chiamata della funzione diamo il valore di "start" a "counter"
  int counter = start;
  //entriamo nel ciclo while che terrà occupato il programma affinchè il valore di "counter" non sarà maggiore del valore di "finish"
  while(counter <= finish) {
    //stampo sulla seriale il valore attuale di "counter"
    Serial.println(counter);
    //incremento counter di 1 con l'operatore ++, si traduce in counter = counter + 1
    counter++;
  }
}

void setup() {
  //avvio la seriale su baudrate 9600
  Serial.begin(9600);
  //attendo e blocco il codice affinchè non venga aperto il Monitor Seriale
  while(!Serial);
  //richiamo la funzione "counter" precedentemente creata e setto come valore di inizio 30 e valore di fine 100
  //verranno stampati tutti i valori includi tra 30 e 100
  counter(30, 100);

  //le operazioni del programma finiscono qui ed entra nel loop
  //per eseguire di nuovo il programma puoi chiudere il Monitor Seriale, riavviare la board e riaprire il Monitor Seriale
}

void loop() {
  

}

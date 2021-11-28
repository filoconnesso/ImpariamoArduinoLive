/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Questo esempio mostra un metodo fornito dal c++ che permette di scorrere tutti i valori di un array senza sapere di preciso quanti elementi quest'ultimo contiene al suo interno
* il metodo è estremamente versatile, sfruttando una variabile di tipo "auto" la quale si auto-adatta al tipo di variabile che forniamo nel ciclo for
* Questo metodo sfrutta un tipo di for che io chiamo foreach
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//definisco una costante con il numero del pin 3, darà il nome al pin del led blu
#define LEDBLUE 2
//definisco una costante con il numero del pin 2, darà il nome al pin del led verde
#define LEDGREEN 3
//definisco una costante con il numero del pin 4, darà il nome al pin del led rosso
#define LEDRED 4
//definisco una costante con il numero del pin 5, darà il nome al pin del led bianco
#define LEDWHITE 5
//definisco una costante con il numero del pin 6, darà il nome al pin del led giallo
#define LEDYELLOW 6

//creo un array di variabili int che conterrà i pin di tutti i led
int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};

void setup() {
  //avvio la seriale con baudrate 115200, ricorda di settare lo stesso baudrate nel Monitor Seriale
  Serial.begin(115200);
  //il ciclo while blocca l'esecuzione del resto del codice affinchè Serial non ritorna un valore true
  //per far in modo che Serial ritorni true bisogna aprire il Monitor Seriale
  //affinchè non si apre il Monitor Seriale il nostro codice resterà bloccato in questo punto e la tua board non eseguirà il resto del programma
  while(!Serial);

  //se hai visto la struttura dei for negli esempi precedenti, avrai notato che questa struttura è ben diversa dal normale
  //questo metodo che io definiscono molto simile al foreach, disponibile su altri linguaggi di programmazione, permette di scorrere tutti gli elementi di un array
  //senza sapere di preciso quanti elementi sono contenuti nell'array in questione
  //questo metodo prevede l'uso di una variabile auto che assumerà la tipolgia di variabile dell'array (in questo caso di tipo int)
  for(auto pin : pins) {
    //pinMode setta come uscita il pin corrente
    pinMode(pin, OUTPUT);
    //digitalWrite scrive sul pin corrente il valore HIGH, quindi accende il led
    digitalWrite(pin, HIGH);
    //attento 300 millisecondi prima di passare la pin successivo
    delay(300);
  }

  //da questo momento in poi il programma passerà al loop
  //dovrai chiudere il Monitor Seriale, riavviare la scheda e riaprire il Monitor Seriale per rieseguire il programma

}

void loop() {
  
}

/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Questo esempo mostra come è possibile sfruttare un array e dei cicli for per eseguire operazioni su diversi pin scrivendo meno codice del solito
* nello specifico abbiamo un effetto ping pong nel setup di 5 led e alla pressione del pulsante 1 si passa al loop dove i tutti i led eseguiranno un blink 
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//definisco una costante con il numero del pin 3, darà il nome al pin del led blu
#define LEDBLUE 3
//definisco una costante con il numero del pin 2, darà il nome al pin del led verde
#define LEDGREEN 2
//definisco una costante con il numero del pin 4, darà il nome al pin del led rosso
#define LEDRED 4
//definisco una costante con il numero del pin 5, darà il nome al pin del led bianco
#define LEDWHITE 5
//definisco una costante con il numero del pin 6, darà il nome al pin del led giallo
#define LEDYELLOW 6

//definisco una costante con il numero del pin 12, darà il nome al pin del pulsante 1
#define BUTTON_1 12

//creo un array di variabili int che conterrà i pin di tutti i led
int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};

void setup() {
  //imposto il pin del pulsante 1 come ingresso settato in pullup, senza resistore sui collegamenti, sfruttando il resistore interno al microcontrollore
  pinMode(BUTTON_1, INPUT_PULLUP);
  //il ciclo for qui sotto setta tutti i pin come uscite (OUTPUT) e li spegne tutti scrivendo con digitalWrite il valore LOW (GND)
  //nel for abbiamo una variabile indice "i" di tipo int che viene inizializzata a 0
  //successivamente faremo girare il ciclo for affinchè "i" resta < del numero di pin inseriti all'interno dell'array
  //la funzione "sizeof" permette di contare il numero di byte di una variabile, nel caso di variabili int dovete sapere che occupano 4 byte (su Arduino Nano RP2040 Connect)
  //un array di 5 variabili int occuperebbe quindi 20 byte, risultato di 4(byte)*5(elementi)=20(byte)
  //dobbiamo successivamente dividere il numero di byte complessivi per il numero di byte di una delle variabili int contenute nell'array (1 elemento)
  //avremo così 20(byte complessivi)/4(byte di un elemento) così da recuperare automaticamente il numero di elementi contenuti nell'array e cioè 5
  //quindi (sizeof(pins) / sizeof(pins[0])) è traducibile in 20 byte dell'array / byte di LEDBLUE o meglio 20 / 4
  //nell'ultima sezione del nostro for abbiamo "i++" che incrementerà ad ogni step del for il valore dell'indice i, fino a quando la condizione resterà soddisfatta
  //se vogliamo dare un senso numerico al for qui sotto si traducerà quindi in for(i = 0; i < 5; i++) { // }
  //l'indice "i" assumerà ogni volta un valore nuovo e verrà usato per ripescare il pin corrente dall'array
  //in questo caso "i" assumerà un valore da 0 a 4, corrispondendo, ad ogni step di for, al valore di ogni posizione dell'array
  //questo permette di scrivere pinMode e digitalWrite solo una volta e non 5 volte, sarà il programma ad eseguire per te le operazioni su tutti i pin
  for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
    //pinMode setta il pin corrente (posizione dell'array tramite l'indice i) come uscita (OUTPUT)
    pinMode(pins[i], OUTPUT);
    //digitalWrite setta il pin corrente (posizione dell'array tramite l'indice i) con il valore LOW (GND)
    digitalWrite(pins[i], LOW);
  }

  //il seguente while esegue i due for contenuti affinchè non venga premuto il pulsante 1
  //nella condizione del for viene controllato con digitalRead il valore del pulsante 1, che se non premuto il pin collegato ad esso avrà valore 1 (HIGH)
  //questo while blocca il programma, servirà premere il pulsante 1 per continuare
  while(digitalRead(BUTTON_1) == HIGH) {
    //for che accende setta tutti i pin ad HIGH
    for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
      //digitalWrite che setta il pin corrente ad HIGH
      digitalWrite(pins[i], HIGH);
      //attendo 50 millisecondi prima di passare al prossimo pin
      delay(50);
    }
    //for che spegne tutti i pin a LOW
    for(int i = (sizeof(pins) / sizeof(pins[0])); i >= 0 ; i--) {
      //digitalWrite che setta il pin corrente a LOW
      digitalWrite(pins[i], LOW);
      //attendo 50 millisecondi prima di passare al prossimo pin
      delay(50);
    }
  }

  //i for contenuti nel while precedente hanno tutti un delay di 50 millisecondi che crea un effetto progressivo di accensione e spegnimento tra un led e l'altro

  //se viene premuto il pulsante 1 e quindi viene interrotto il while precedente, spegno tutti i led
  for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
      //digitalWrite che setta il pin corrente a LOW
      digitalWrite(pins[i], LOW);
  }

  //il programma continua ed entra nel loop

}

void loop() {
  //i for successivi creeranno un effetto blink su tutti i led
  
  //for che accende tutti i led
  for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
     //digitalWrite che setta il pin corrente ad HIGH
     digitalWrite(pins[i], HIGH);
  }
  //aspetto 500 millisecondi prima di passare al for che spegnerà tutti i led
  delay(500);
  //for che spegne tutti i led
  for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
     //digitalWrite che setta il pin corrente a LOW
     digitalWrite(pins[i], LOW);
  }
  //aspetto 500 millisecondi prima di passare al for che accenderà tutti i led
  delay(500);
}

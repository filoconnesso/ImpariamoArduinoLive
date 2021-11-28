/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* L'esempio mostra come sia possibile settare la modalità di utilizzo e il valore di 2 o più pin utilizzando un array e un ciclo for
* il metodo mostrato qui sotto ci permetterà di scrivere meno codice del solito
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

//creo un array di variabili int che conterrà i pin di tutti i led
int pins[] = {LEDBLUE, LEDGREEN, LEDRED, LEDWHITE, LEDYELLOW};
//creo un array di variabili bool che conterrà gli stati di tutti i led all'accensione della board, in questo caso tutti gli stati a LOW
bool status[] = {LOW, LOW, LOW, LOW, LOW};

void setup() {
  //avvio la seriale con baudrate 115200, ricorda di settare lo stesso baudrate nel Monitor Seriale
  Serial.begin(115200);
  //il ciclo while blocca l'esecuzione del resto del codice affinchè Serial non ritorna un valore true
  //per far in modo che Serial ritorni true bisogna aprire il Monitor Seriale
  //affinchè non si apre il Monitor Seriale il nostro codice resterà bloccato in questo punto e la tua board non eseguirà il resto del programma
  while(!Serial);
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
  //nel for abbiamo anche l'inversione della posizione attuale dello status del pin corrente
  for(int i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
    //inverto lo stato del pin corrente da LOW (valore settato nell'array status) ad HIGH
    status[i] = !status[i];
    //pinMode setta il pin corrente come uscita (OUTPUT)
    pinMode(pins[i], OUTPUT);
    //digitalWrite scrive il valore attuale di status (in questo caso HIGH, poichè invertito poco prima) sul pin attuale
    digitalWrite(pins[i], status[i]);
    //attendo 300 millisecondi prima di passare al prossimo pin
    delay(300);
  }

  //il for qui sopra creerà un effetto di accensione progressiva dei led
  //tra un'accensione di un pin e l'altro ci sarà una pausa di 300 millisecondi

  //Scrivo sulla seriale il conteggio dei pin attuali
  Serial.print("Pin counter : ");
  //uso sizeof, come descritto precedentemente, per stampare il numero di pin presenti nell'array
  Serial.print((sizeof(pins) / sizeof(pins[0])));
  //creo una nuova linea vuota sulla seriale
  Serial.println();

  //da qui si entra nel loop, per rieseguire l'operazione bisognerà chiudere il Monitor Seriale, riavviare la board e riaprire il Monitor Seriale

}

void loop() {
  
}

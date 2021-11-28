/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Questo esempio mostra come bloccare il setup in casi specifici, facciamo accendere il led per 5 volte e lo facciamo spegnere per altre 5 volte, creando un blink temporaneo
* successivamente il programma entrerà nel loop
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//definisco una costante con il numero del pin 2, darà il nome al pin del led blu
#define LEDBLUE 2

//creo una variabile booleana (true o false) che terrà traccia del valore del pin del led blu, viene inizializzata a false (LOW, led spento)
bool statusBLUE = false;
//creo una variabile intera che avrà il compito di counter nel while contenuto nel setup, la setto a 0
int counter = 0;

void setup() {
  //avvio la seriale con baudrate 115200, ricorda di settare lo stesso baudrate nel Monitor Seriale
  Serial.begin(9600);
  //il ciclo while blocca l'esecuzione del resto del codice affinchè Serial non ritorna un valore true
  //per far in modo che Serial ritorni true bisogna aprire il Monitor Seriale
  //affinchè non si apre il Monitor Seriale il nostro codice resterà bloccato in questo punto e la tua board non eseguirà il resto del programma
  while(!Serial);
  //scrivo sulla seriale la parola "SETUP"
  Serial.println("SETUP");
  //setto il pin del led blu come uscita
  pinMode(LEDBLUE, OUTPUT);
  //il while corrente continuerà affinchè la variabile counter sarà minore o uguale a 10
  while(counter <= 10) {
    //imposto la variabile statusBLUE a true se è false e viceversa, in sostanza inverto il suo valore
    statusBLUE = !statusBLUE;
    //Scrivo il valore attuale di statusBLUE
    Serial.print("led : ");
    Serial.print(statusBLUE);
    Serial.println();
    //digitalWrite permette di scrivere un valore digitale (0 o 1) al pin che scegliamo, in questo caso LEDBLUE
    //se il valore di statusBLUE è true il valore settato al digitalWrite sarà 1
    //se il valore di statusBLUE è false il valore settato al digitalWrite sarà 0
    //con digitalWrite setto un valore digitale al led blu, dando come valore di riferimento la variabile statusBLUE
    digitalWrite(LEDBLUE, statusBLUE);
    //incremento di 1 il valore della variabile counter
    //l'operatore ++ si traduce in counter = counter + 1
    counter++;
    //aspetto 1000 millisecondi (1 secondo) prima di passare al prossimo step del ciclo while
    delay(1000);
  }

  //una volta che counter sarà maggiore di 10 il programma continuerà passando al loop

}

void loop() {
  //entrando nel loop il programma scriverà velocemente sulla seriale la parola "LOOP"
  Serial.println("LOOP");
}

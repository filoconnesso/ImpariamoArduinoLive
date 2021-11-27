/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Il seguente codice esegue il blink di due led differenti, per passare da un blink e l'altro si usano due pulsanti
* ogni pulsante permette di uscire da un determinato blink
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//definisco una costante con il numero del pin 3, darà il nome al pin del led blu
#define LEDBLUE 3
//definisco una costante con il numero del pin 2, darà il nome al pin del led verde 
#define LEDGREEN 2
//definisco una costante con il numero del pin 12, darà il nome al pin del pulsante 1
#define BUTTON_1 12
//definisco una costante con il numero del pin 11, darà il nome al pin del pulsante 2
#define BUTTON_2 11

//creo una variabile booleana (true o false) che terrà traccia del valore del pin del led blu, viene inizializzata a false (LOW, led spento)
bool statusBLUE = false;
//creo una variabile booleana (true o false) che terrà traccia del valore del pin del led verde, viene inizializzata a false (LOW, led spento)
bool statusGREEN = false;

void setup() {
  //imposto il pin del led blu come uscita
  pinMode(LEDBLUE, OUTPUT);
  //imposto il pin del led verde come uscita
  pinMode(LEDGREEN, OUTPUT);  
  //imposto il pin del pulsante 1 come ingresso settato in pullup, senza resistore sui collegamenti, sfruttando il resistore interno al microcontrollore
  pinMode(BUTTON_1, INPUT_PULLUP);
  //imposto il pin del pulsante 2 come ingresso settato in pullup, senza resistore sui collegamenti, sfruttando il resistore interno al microcontrollore
  pinMode(BUTTON_2, INPUT_PULLUP);
}

void loop() {
  //il while settato a 1 è un while infinito, il quale può essere chiuso solo e soltanto con un un break
  //il while esegue un blink sul led blue
  while(1) {
    //imposto la variabile statusBLUE a true se è false e viceversa, in sostanza inverto il suo valore
    statusBLUE = !statusBLUE;
    //digitalWrite permette di scrivere un valore digitale (0 o 1) al pin che scegliamo, in questo caso LEDBLUE
    //se il valore di statusBLUE è true il valore settato al digitalWrite sarà 1
    //se il valore di statusBLUE è false il valore settato al digitalWrite sarà 0
    digitalWrite(LEDBLUE, statusBLUE);
    //con il seguente if controllo se il pin del pulsante 1 assume un valore a LOW (GND)
    //il pin mantiene un valore ad HIGH per tutto l'arco del tempo che il pulsante 1 non è premuto
    if(digitalRead(BUTTON_1) == LOW) {
      //se il pulsante 1 viene premuto il led blue viene spento
      digitalWrite(LEDBLUE, LOW);
      //break chiude il ciclo e passa al while successivo
      break;   
    } 
    //se il pulsante 1 non viene premuto attende 100 millisecondi prima di passare a un nuovo step del ciclo while corrente
    delay(100);
  }
  //se il ciclo precedente si interrompe il nostro codice entra nel ciclo while successivo
  while(1) {
    //imposto la variabile statusGREEN a true se è false e viceversa, anche in questo caso, come per statusBLUE viene invertito il suo valore
    statusGREEN = !statusGREEN;
    //con digitalWrite setto un valore digitale al led verde, dando come valore di riferimento la variabile statusGREEN
    digitalWrite(LEDGREEN, statusGREEN);
    //attendo che venga premuto il pulsante 2 per interrompere il ciclo corrente
    if(digitalRead(BUTTON_2) == LOW) {
      //se premo il pulsante 2 spengo il led verde
      digitalWrite(LEDGREEN, LOW);
      //con break interrompo il ciclo che si occupa di far lampeggiare il led verde
      //se richiamo break sfrutto il loop per tornare al ciclo del blink led blu
      break;   
    }  
    //se il pulsante 2 non viene premuto attende 100 millisecondi prima di passare a un nuovo step del ciclo while corrente
    delay(100);
  }  
  
}

/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Il codice seguente codice esegue un blink del led all'avvio della scheda, bloccando il setup all'ingresso del ciclo do while
* il ciclo do while attenderà che venga premuto il pulsante 1 per poi continuare entrando nel loop
* do while è un ciclo while classico con l'unica differenza che le istruzioni dentro di esso vengono eseguite almeno una volta
* questo accade perchè la condizione del ciclo viene controllata alla fine di ogni step del ciclo
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//definisco una costante con il numero del pin 3, darà il nome al pin del led blu
#define LEDBLUE 3
//definisco una costante con il numero del pin 12, darà il nome al pin del pulsante 1
#define BUTTON_1 12

//creo una variabile booleana (true o false) che terrà traccia del valore del pin del led blu, viene inizializzata a false (LOW, led spento)
bool statusBLUE = false;
//creo una variabile booleana (true o false) che terrà traccia del valore del pin del pulsante 1
int statusBUTTON;

void setup() {

 Serial.begin(115200);

 //imposto il pin del led blu come uscita
 pinMode(LEDBLUE, OUTPUT);
 //imposto il pin del pulsante 1 come ingresso settato in pullup, senza resistore sui collegamenti, sfruttando il resistore interno al microcontrollore
 pinMode(BUTTON_1, INPUT_PULLUP);

 //viene eseguito per prima cosa il codice contenuto nel ciclo do while
 //infatti la differenza sostanziale tra il while e il do while è che nel primo
 //viene controllata prima la condizione e se è soddisfatta il ciclo viene eseguito fino a quando quest'ultima resta soddisfatta
 //nel do while il contenuto del ciclo verrà comunque eseguito almeno una volta per poi continuerà solo se la condizione controllata alla fine è soddisfatta 
 do {
   //imposto la variabile statusBLUE a true se è false e viceversa, in sostanza inverto il suo valore
   statusBLUE = !statusBLUE; 
   //imposto la variabile statusBLUE in base al valore del pin collegato al pulsante
   //digitalRead permette di leggere il pin settato nelle parentesi tonde
   statusBUTTON = digitalRead(BUTTON_1);
   //scrivo in seriale il valore del pin collegato al pulsante (1 o 0) in base al pulsante premuto o meno
   Serial.println(statusBUTTON);
   //digitalWrite permette di scrivere un valore digitale (0 o 1) al pin che scegliamo, in questo caso LEDBLUE
   //se il valore di statusBLUE è true il valore settato al digitalWrite sarà 1
   //se il valore di statusBLUE è false il valore settato al digitalWrite sarà 0
   digitalWrite(LEDBLUE, statusBLUE);
   //se il pulsante 1 non viene premuto attende 100 millisecondi prima di passare a un nuovo step del ciclo do while corrente
   delay(100);
   //la considzione che controlla se il pulsante 1 è premuto o meno avviene alla fine di ogni step del ciclo do while
   //se il pulsante resta rilasciato il setup resterà bloccato in questo ciclo do while affinchè non viene premuto il pulsante 1
   //prova a cambiare la condizione da "statusBUTTON == HIGH" a "statusBUTTON == LOW" 
   //ti accorgerai che il programma entrerà subito nel loop ma accenderà il led, questo perchè eseguirà almeno un ciclo del do while
 } while (statusBUTTON == HIGH);

 //uscendo dal ciclo do while il programma entrerà nel loop

}

void loop() {
 //verrà stampata velocemente la parola "loop" nella seriale affinchè la board non viene spenta
 Serial.println("loop");
}

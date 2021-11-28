/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Il metodo goto è un metodo che non viene quasi mai usato nei codici di Arduino ma a mio avviso ci permette di creare codici a stati molto velocemente e in modo versatile
* al goto vengono abbinati alcuni elementi del linguaggio di programmazione chiamati "label"
* le label le possiamo riconoscere dal fatto che vengono scritte nel seguente modo :
* 
* label_esempio :
*   //codice da eseguire se si entra nella label_esempio
*   
* questo metodo di programmazione non è ben visto dalla maggior parte degli sviluppatori perchè è difficile da debuggare in caso di errori
* una cosa molto importante da sapere del goto è che può richiamare le label solo ed esclusivamente nella stessa funzione nella quale questi elementi sono collocati
* questo metodo proviene dal linguaggio di programmazione C
* 
* In questo specifico esempio è possibile passare da un blink di un led e l'altro usando due pulsanti
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
//creo una variabile booleana (true o false) che terrà traccia dello stato di inizializzazione del nostro programma
//utilizzeremo questa variabile per richiamere il blink del led blu solo una volta all'ingresso del loop
bool statusSTART = false;

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
  //il seguente if controlla che la variabile booleana statusSTART sia a false
  //il valore di questa variabile come si può vedere nella riga 35 (prima del setup) viene inizializzato a false
  //se statusSTART è false entra nell'if
  if(!statusSTART) {
    //per prima cosa setta il valore di statusSTART a true in modo tale che questo if non venga più soddisfatto da questo momento in poi
    statusSTART = true;
    //richiama la label blinkblue e da qui in poi inizia il programma
    goto blinkblue;
  }  

  //label "blinkblue" contiene il ciclo while che farà lampeggiare il led blu
  blinkblue :
    //ciclo while infinito che esegue il blink del led blu
    while(1) {
      //imposto la variabile statusBLUE a true se è false e viceversa, in sostanza inverto il suo valore
      statusBLUE = !statusBLUE;
      //digitalWrite permette di scrivere un valore digitale (0 o 1) al pin che scegliamo, in questo caso LEDGREEN
      //se il valore di statusGREEN è true il valore settato al digitalWrite sarà 1
      //se il valore di statusGREEN è false il valore settato al digitalWrite sarà 0
      //in questo caso il led verde resterà spento per tutto il tempo del blink del led blu
      digitalWrite(LEDGREEN, LOW);  
      //con digitalWrite setto un valore digitale al led blu, dando come valore di riferimento la variabile statusBLUE
      digitalWrite(LEDBLUE, statusBLUE);
      //se il pulsante 1 non viene premuto attende 300 millisecondi prima di passare a un nuovo step del ciclo do while corrente
      delay(300);
      //con il seguente if controllo se il pin del pulsante 1 assume un valore a LOW (GND)
      //il pin mantiene un valore ad HIGH per tutto l'arco del tempo che il pulsante 1 non è premuto
      if(digitalRead(BUTTON_1) == LOW) {   
        //il pulsante 1 è stato premuto e di conseguenza goto richiamerà la label "blinkgreen" uscendo dal while del blink del led blu   
        goto blinkgreen;
      }
    }

  //label "blinkgreen" contiene il ciclo while che farà lampeggiare il led verde
  blinkgreen :
    //ciclo while infinito che esegue il blink del led verde
    while(1) {
      //imposto la variabile statusGREEN a true se è false e viceversa, anche in questo caso, come per statusBLUE viene invertito il suo valore
      statusGREEN = !statusGREEN;
      //digitalWrite permette di scrivere un valore digitale (0 o 1) al pin che scegliamo, in questo caso LEDBLUE
      //se il valore di statusGREEN è true il valore settato al digitalWrite sarà 1
      //se il valore di statusGREEN è false il valore settato al digitalWrite sarà 0
      //in questo caso il led blue resterà spento per tutto il tempo del blink del led verde
      digitalWrite(LEDBLUE, LOW);
      //con digitalWrite setto un valore digitale al led verde, dando come valore di riferimento la variabile statusGREEN
      digitalWrite(LEDGREEN, statusGREEN);
      //se il pulsante 2 non viene premuto attende 300 millisecondi prima di passare a un nuovo step del ciclo do while corrente
      delay(300);
      //con il seguente if controllo se il pin del pulsante 2 assume un valore a LOW (GND)
      //il pin mantiene un valore ad HIGH per tutto l'arco del tempo che il pulsante 2 non è premuto
      if(digitalRead(BUTTON_2) == LOW) {
        //il pulsante 2 è stato premuto e di conseguenza goto richiamerà la label "blinkblue" uscendo dal while del blink del led verde  
        goto blinkblue;
      }
    }

}

/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 8 di Impariamo Arduino Live : https://youtu.be/nKjv-KkZZig
* Questo esempio dimostra l'utilità di dare una funzione di callback ad un'altra funzione, questo permette di richiamare un'operazione esterna alla funzione corrente
* nel caso specifico vengono gestiti due pulsanti con un led, premendo il pulsante 1 il led si accende, premendo il pulsante 2 il led si spegne
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//creo una funzione chiamata "pressed" con 3 argomenti
//il primo argomento è di tipo int (pin) e conterrà il pin collegato al pulsante
//il secondo argomento è di tipo void (func) e conterrà la funzione detta di callback
//il terzo argomento è di tipo int (exitpin) e conterrà il pin collegato al led da controllare
//per quanto riguarda la funzione di callback anch'essa ha un argomento di tipo int
void pressed(int pin, void (*func)(int), int exitpin) {
  //al suo interno la funzione "pressed" controlla che il pin del pulsante indicato con l'argomento "pin" assuma valore LOW
  //in tal caso i pulsanti sono collegati in pullup e questo significa che il valore dei pin a loro collegati sarà in HIGH se il pulsante non viene premuto
  //se il pulsante viene premuto il valore del pin collegato ad esso assumerà un valore LOW (GND)
  if(digitalRead(pin) == LOW) {
    //se il pin del pulsante assume un valore LOW (quindi il pulsante viene premuto) richiama la funzione di callback
    //nel nostro caso le due funzioni di callback che useremo saranno "ledon" e "ledoff"
    //in questo esempio func(exitpin) si traducerà in ledon(2) o ledoff(2) in base al pulsante premuto
    func(exitpin);
  }
}

//creo una funzione "ledon" che ha come argomento un int che indicherà il pin da portare ad HIGH ogni qualvolta venga richiamata la funzione
void ledon(int pin) {
  //digitalWrite scrive il valore HIGH al pin indicato con l'argomento "pin", in questo esempio useremo il pin 2
  digitalWrite(pin, HIGH);
}
//creo una funzione "ledoff" che ha come argomento un int che indicherà il pin da portare a LOW ogni qualvolta venga richiamata la funzione
void ledoff(int pin) {
  //digitalWrite scrive il valore LOW al pin indicato con l'argomento "pin", in questo esempio useremo il pin 2
  digitalWrite(pin, LOW);
}

void setup() {
  //pinMode che imposta il pin 12 (pulsante 1) come input in pullup, questo permette di sfruttare la resistenza interna al microcontrollore
  //il pin assume un valore HIGH che potrà essere portato a GND
  pinMode(12, INPUT_PULLUP);
  //pinMode che imposta il pin 11 (pulsante 2) come input in pullup, questo permette di sfruttare la resistenza interna al microcontrollore
  //il pin assume un valore HIGH che potrà essere portato a GND
  pinMode(11, INPUT_PULLUP);
  //pinMode che imposta il pin 2 (LEDGREEN) come output (uscita)
  pinMode(2, OUTPUT);
}

void loop() {
  //le funzioni presenti nel loop vengono richiamate continuamente, senza che il codice venga bloccato
  //in questo caso, come abbiamo visto pocanzi, la funzione "pressed" controlla che il pin indicato (12 o 11 in questo esempio) assuma un valore LOW dopo la pressione del  pulsante

  //controllo pressed sul pin 12 e richiamo la funzione ledon indicando il pin 2 da accendere 
  pressed(12, ledon, 2);
  //controllo pressed sul pin 11 e richiamo la funzione ledoff indicando il pin 2 da spegnere
  pressed(11, ledoff, 2);
}

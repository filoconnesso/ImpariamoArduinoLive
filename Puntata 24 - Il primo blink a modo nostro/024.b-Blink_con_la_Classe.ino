/*****************************************************************
 *               revisione sketch by Concetto G.                 *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #24                  *  
 *                     Il primo blink a modo nostro              * 
 *           https://www.youtube.com/watch?v=C9ipVaE4BMw         *        
 *                                                               *
 *             blink con la classe            00:27:04           *
 *                                                               *
 *****************************************************************
*/

/* Creiamo una classe per creare un timer, non bloccante, dove una funzione andrà a TRUE quando il tempo attuale è supeiore al tempo settato */
class Timer {  // nome della classe 
	private :  // dichiariamo le variabili che all'interno della classe sono di tipo privato, visibili soltanto dalla classe
	unsigned long curMillis;  // variabile per il tempo corrente
	unsigned long prevMillis;  // variabile per il tempo precedente
	unsigned long delayMillis;  // variabile per il tempo del timer
	bool goStatus = false;
	/* il distruttore ha lo stesso nome del costruttore con 
	   antemposto il sombolo di tilde (alt 126 ~) */
	public :  // variabili visibili all'esterno della classe
	Timer() {  // costruttore della classe
		prevMillis = millis();  // quando creiamo l'oggetto del timer si aggiorna i millis precedenti 
	}
	~Timer() {  // distruttore della classe
		
	}
	void setTime(unsigned long newDelayMillis){ // creiamo una funzione set Time che permette di settare il tempo al timer
		delayMillis = newDelayMillis;
	}
	
	bool go(){  // funzione principale che, in funzione al tempo settato restituisce un valore booleano che avvia o ferma il timer
		curMillis = millis(); // settiamo la variabile al tempo attuale
		/* questo if è il cuore del timer, controlla se il valore del tempo corrente meno il valore del tempo precedente è o meno uguale al valore del tempo settato nel timer */
		if((unsigned long)curMillis - prevMillis == delayMillis ){
			prevMillis = curMillis;
			goStatus = true;
		} else {
			goStatus = false;
		}
		return goStatus;  // valore booleano che verrà utilizzato nel loop
	}
	
}; // fine della classe

Timer blinkLed; /* viene creato un timer di nome blinkLed, possiamo creare quanti
                   time vogliamo e settarli individualmente con valori diversi, 
                   agiscono contemporaneamente e non si interferiscono l'un l'altro */

Timer printHelloWorld; /* viene creato un secondo timer */

bool ledStatus = false;

void setup(){
	Serial.begin(9600);  // inizializziamo la seriale
	while(!Serial); // fino a quando non apriamo la seriale non verrà stampato niente
	pinMode(LED_BUILTIN, OUTPUT);  // settiamo il pin del led interno come uscita 

	blinkLed.setTime(50); // il timer blinkLed, creato alla riga 48, viene settato a 50ms, il nostro time agisce ogni 50  millisecondi

  printHelloWorld.setTime(1000); // il timer printHelloWorld, creato alla riga 52, viene settato a 1000ms, il time agisce una volta a secondo
}

void loop(){
  // si fa eseguire il PRIMO  timer per il blink
	if(blinkLed.go()){ // controlliamo la variabile booleana della funzione go, 
		ledStatus = !ledStatus; // se if è  vero ,inverte lo stato della variabile ledStatus
		digitalWrite(LED_BUILTIN, ledStatus); // accende e spegne il led ogni secondo
	}
 // si fa eseguire il SECONDO  timer per il print
 if(printHelloWorld.go()){ 
   Serial.println("HELLO WORLD");
 }
}

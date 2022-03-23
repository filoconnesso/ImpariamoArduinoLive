/********************************************************
 *                     Filo Connesso                    *
 *               Impariamo Arduino Live #26             *  
 *            Gestire i pulsanti con le classi          * 
 *      https://www.youtube.com/watch?v=kBNIo0qK864     *        
 *  la classe viene spiegata a partire dal minuto 58:27 *
 ********************************************************
*/

class Button {
	private :
	unsigned long prevMillis;
	int curPin;
	int curPinMode;
	bool curButtonStatus = false; // stato attuale della lettura del pulsante, il digitalRead
	bool curSwitchStatus = false; // stato attuale dello switch, ogni volta che premiamo il 
								                // pulsante passa da false a true e richiama la funzione assegnata; 
	bool buttonPressed = false; // controlla se il pulsante è premuto,passando a true quando è premuto;
	public :
	Button(int pin, int mode){ // costruttore della classe, serve a inizializzare il nostro oggetto classe,
							               // e viene richiamato nell'ultimo rigo prima del void setup();
		prevMillis = millis(); // creato l'oggetto  classe aggiorno con i millis attuali, che ci servirà per il debounce;
		curPin = pin; // aggiorniamo con il valore del pin dove è collegato il pulsante;
		curPinMode = mode; /* aggiorniamo  con il modo con cui è montato il pulsante, INPUT_PULLUP, 
		se utilizziamo le resistenze interne o INPUT se il pulsante è collegato
		con le resistenze esterne;*/
		pinMode(curPin, curPinMode);  
	} // abbiamo creato il nostro oggetto che possiamo chiamarlo come vogliamo, nell'esempio viene chiamato miopulsante;
	~Button(); // distruttore della classe;
	// metodo1 dell'oggetto classe creato, che ci permette di controllare se il pulsante è premuto;
	bool pressed(){ 
		curButtonStatus = digitalRead(curPin); // aggiorno con il digitalRead, del pin settato dove è collegato il pulsante;
		/*  L'if che segue serve a controllare se il pulsante è collegato in pullup a invertire lo stato
			della variabile perché se il pulsante è in INPUT quando si preme la variabile passa da LOW
			a HIGH, mentre in PULLUP lo stato  passa da LOW a HIGH, ma dato che il metode è un BOOL,
			deve ritornare sempre un HIGH, se il pulsante è in PULLUP non funziona, quindi per poter
			utilizzare questo metodo in tutte le situazioni, nel caso abbia il pulsante il PULLUP la 
			variabile la inverto di stato;*/
		if(curPinMode == INPUT_PULLUP){ 
			curButtonStatus = !curButtonStatus; // inverte lo stato;
		}
		return curButtonStatus; // se il pulsante è premuto, 
		// qulasiasi sia il modo in cui lo abbiamo collegato il return è sempre HIGH;
	}
	/*  metodo2, fa da interruttore, cioé quando premo il pulsante va a 1 e ci deve restare 
		fino a quando non rilascio il pulsante, appena rilascio il pulsante va a 0;*/
	bool buttonSwitch() { 
		curButtonStatus = digitalRead(curPin);
		if(curPinMode == INPUT_PULLUP){
			curButtonStatus = !curButtonStatus;
		}
		/* questo if verrà richiamato una volta sola, all'inizio la condizione è vera, aggiorniamo i millis
			al tempo attuale mettiamo a TRUE la variabile buttonPressed e invertiamo lo stato della variabile
			curSwitchStatus, adesso la condizione dell'if sarà sempre falsa, fino alla prossima pressione del
			pulsante; */
		if(curButtonStatus == true && !buttonPressed){ 
			prevMillis = millis();
			buttonPressed = true;
			curSwitchStatus =  !curSwitchStatus;
		}
		if((unsigned long)millis() -prevMillis >= 150){ /* questo if è il debounce, evita i saltelli, 
		che potebbero falsare la condizione, facendo passare lo stato da HIGH a FALSE più volte, 
		in questo modo per 150 millisecondi abbiamo solo una condizione */ 
			if(curButtonStatus == false){
				buttonPressed = false;
			}
		}
		return curSwitchStatus;
	}
	/*  metodo3, questo metodo non ritorna niente, perché il suo compito è fare le stesse operazioni
		del metodo2, con la differenza che ogni volta che si preme un pulsante richiama function(), 
		che è inserito come argomento */
	void press(void(*function)()){  
		curButtonStatus = digitalRead(curPin);
		if(curPinMode == INPUT_PULLUP){
			curButtonStatus = !curButtonStatus;
		}
		if(curButtonStatus == true && !buttonPressed){
			prevMillis = millis();
			buttonPressed = true;
			function();
		}
		if((unsigned long)millis() - prevMillis >=150){
			if(curButtonStatus == false){
				buttonPressed = false;
			}
		}
	}
};  // fine della classe

int counter = 0;
bool attivaAllarme = false;

Button miopulsante(12, INPUT_PULLUP); // costruttore 

void setup(){
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

/*  funzione counter che viene richiamata una sola volta alla pressione del pulsante 
	se tengo premuto il pulsante counter non viene aggiornata, per incrementarlo dobbiamo
	rilasciare il pulsante e ripremerlo di nuovo */
void updateCounter() {
	counter++;
	Serial.println(counter);
}

void loop(){
	/* al metodo press posso dare come argomento una funzione specifica 
		in questo modo posso utilizzare la stessa classe per tutti i pulsanti che voglio
		senza che si interferiscano tra di loro, ogni pulsante richiama una 
		propria funzione */
	miopulsante.press(updateCounter); // tutte le volte che premo un pulsante viene richamata la funzione counter
	
	if(miopulsante.pressed()){
		digitalWrite(13, HIGH);
	}else {
		digitalWrite(13, LOW);
	}
	attivaAllarme = miopulsante.buttonSwitch();
}

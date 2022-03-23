/*****************************************************************
 *               revisione sketch by Concetto G.                 *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #25                  *  
 *                     I pulsanti su Arduino                     * 
 *      https://www.youtube.com/watch?v=2JhSIqSuVyY&t=120s       *        
 *                                                               *
 *       6.  Pulsante esterno con resistenza      00:55:05       *
 *****************************************************************
*/
#define BUTTON 12  // Abbiamodefinito il pulsante che è collegato al pin 12 
#define LED 13
int counter = 0; 
bool pressed =  false; // controlla quando il pulsante è premuto 
unsigned long prevTime; // variabile usata per i millis
bool statusLed = false;  //variabile per il toggle dei led

void setup(){
	Serial.begin(9600);
	
	pinMode(BUTTON, INPUT); /* Il pulsante in questa configurazione  il pulsante è in LOW quando viene premuto  va in HIGH */
	pinMode(LED, OUTPUT);
}

void toggle(){
	statusLed = !statusLed;  // invertiamo lo stato della variabile
	digitalWrite(LED, statusLed); // accendiamo il led con il valore della variabile statusled
}
void loop() {
	/* Questo if controlla se è stato premuto il pulsante e contemporaneamente (&&) se non sia stato premuto prima che sia passato un tempo prestabilito, nell'if successivo */
	if(digitalRead(BUTTON) == HIGH && pressed == false){ 
		 prevTime = millis(); //quando si preme il pulsante, aggiorniamo la variabile con i millis attuali
		 counter++; // incrementiamo counter, di una unità
		 Serial.println(counter); // scriviamo sulla seriale il valore di counter
		 toggle(); // richiamiamo la funzione toggle per accendere il led
		 pressed = true;
	 }
	 /* Questo if è il debounce, con cui controlliamo i millis, fino a quando non passano i millisecondi indicati, nell'esempio (200) */
	 if((unsigned long)millis() - prevTime >= 200){
		if(digitalRead(BUTTON) == LOW){ // se nel tempo dei mmillis settato, abbiamo rilasciato il pulsante 
			pressed = false; /* rimettiamo a false la variabile, così sarà disponibile per la prossima pressione del pulsante */
		} 
	 } 
	
}

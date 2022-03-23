/*****************************************************************
 *               revisione sketch by Concetto G.                 *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #25                  *  
 *                     I pulsanti su Arduino                     * 
 *      https://www.youtube.com/watch?v=2JhSIqSuVyY&t=120s       *        
 *       1.  il codice inizia dal minuto          00:26:10       *
 *       2.  contatore senza debounce             00:31:30       *
 *       3.  contatore controllato senza debounce 00:34:50       *
 *****************************************************************
*/
#define BUTTON 12  // Abbiamodefinito il pulsante che è collegato al pin 12 
#define LED 13
int counter = 0; //(2)
bool pressed =  false; // controlla quando il pulsante è premuto (2)

void setup(){
	Serial.begin(9600);
	
	pinMode(BUTTON, INPUT_PULLUP); /* Il pulsante è in configurazione PULLUP cioé utilizza le restenze interne di arduino, in questa configurazione il pulsante è in HIGH quando viene premuto  va in LOW */
	pinMode(LED, OUTPUT);
}

void loop(){
	/* ***********
	 *     1.    *
	 * ***********/
	// per intercettare la pressione del pulsante
	/* il codice che segue e' il modo piu' semplice per controllare lo stato del pulsante, quando si premo accende il LED, quando viene rilasciato spegne il LED, in questo modo non abbiamo nessun problema di bounce, */
	if(digitalRead(BUTTON) == LOW){
		digitalWrite(LED, HIGH);
	} else {
		digitalWrite(LED, LOW);
	} //   > > > > > > > >  END 1  < < < < < < < <
	
	/* ***********
	 *     2.    *
	 * ***********/
	// Se si vuole invece attivare un contatore ogni volta che si preme il pulsante
	if(digitalRead(BUTTON) == LOW){
		counter++;
		Serial.println(counter);
	} //   > > > > > > > >  END 2  < < < < < < < <
	
	/* In questo modo però se si mantiene il pulsante premuto più a lungo il contatore si incrementa in maniera incontrollata in funzione del tempo di durata della pressione sul tasto */
	
	/* ***********
	 *     3.    *
	 * ***********/
	/* Se si vuole invece che il contatore si incrementi di una unità ad ogni pressione del tasto, indipendentemente dal tempo di durata della pressione */
	if(digitalRead(BUTTON) == LOW){
		if(!pressed){   // questa e' una trappola per il pulsante quando viene premuto,  
			pressed = true; /* cambio di stato che blocca l'if, fino a quando non viene rilasciato il pulsante, viene rieseguito alla successiva pressione sul tasto */   
			counter++;  // si incrementa di una sola unità
			Serial.println(counter);
		}
	} else {  // quando viene rilasciato il pulsante
		pressed = false;
	}  //   > > > > > > > >  END 3  < < < < < < < <

}
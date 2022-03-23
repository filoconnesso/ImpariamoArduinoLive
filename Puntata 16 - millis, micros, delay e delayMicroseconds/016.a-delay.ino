/****************************************************************
 *               revisione sketch by Concetto G.                *
 ****************************************************************
 *                         Filo Connesso                        *
 *                   Impariamo Arduino Live #16                 *
 *          millis, micros, delay e delayMicroseconds           *
 *          https://www.youtube.com/watch?v=nqL65fmKfSA         *
 *                                                              *
 *      1.      Reference Arduino -  Time       00:08:50        *
 *      2.      delay()                         00:13:20        *
 *      3.      millis()                        00:26:55        *
 *      4.      micros()                        01:00:15        *
 *      5.      delayMicroseconds()             01:03:05        *
 *      6.      Discord                         01:07:53        *
 *                                                              *
 ****************************************************************
*/

//  -----------------> 2. delay() <-------------------

// il delay() è una funzione bloccante, durante il tempo in esso impostato arduino blocca l'esecuzione del codice

// assegnato il nome LED al pin 13
#define LED 13

// definiamo una variabile di tipo Booleana chiamata status e gli assegniamo lo stato false
bool status = false;

void setup() {
	
	//inizializziamo la seriale
	Serial.begin(115200);
	
	// settiamo il pin LED come uscita OUTPUT
    pinMode(LED, OUTPUT);
	
}

void loop() {
	// accendiamo o spegniamo il LED in base al valore della variabile [status] che può essere [true] o [false]
	digitalWrite(LED, status);
	
	// invertiamo ilvalore della variabile [status], da true diventa false e viceversa
    status = !status;
	
	// scriviamo sulla seriale 
    Serial.println("test");
	
	/* viene impostato  un tempo di attesa di un secondo delay(1000), 1000 millisecondi, in questo modo il led si accende per un secondo e poi resta spento per un secondo e così via */
    delay(1000);
	
}

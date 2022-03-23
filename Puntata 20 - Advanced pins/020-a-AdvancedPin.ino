/*****************************************************************
 *                revisione sketch by Concetto G.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #20                  *  
 *                   Advanced pins, tone, pulsin, etc            * 
 *            https://www.youtube.com/watch?v=7b2X7g5qFgo        *      
 *                                                               *
 *    1.		Reference Arduino - Advanced I/O  00:06:38           *
 *		2.		tone()								            00:07:44	         *
 *		3.		noTone()							            00:11:33	         *
 *		4.		pulseIn()							            00:12:40	         *
 *		5.		Schema fritzing	pulsante			    00:25:10           * 
 *		6.		codice	pulseIn() 					      00:28:14	         *
 *		7.		codice tone()						          00:46:25	         *
 *		8.		Schema fritzing buzzer				    01:23:33	         *
 *		9.		codice pulseInLong()				      01:32:03        	 *
 *                                                               *
 *****************************************************************
*/

//  -----------------> 4. pulseIn() <-------------------

#define PULSANTE 12 // assegnato il nome PULSANTE al pin 12 
#define LED 13    // assegnato il nome LED al pin 13
unsigned long durata; /* definiamo una variabille di nome [durata] e di tipo [unsigned long]
						 (numero intero positivo lungo(2^32-1) poco più di 4 miliardi) */
bool statoLed = false;	// definiamo una variabile di tipo Booleana statoLed e gli
						// assegnamo lo stato false
void setup() {

	Serial.begin(9600);	// inizializziamo la seriale con una velocità di 9600 bps 

	pinMode(PULSANTE, INPUT); // settiamo il pin PULSANTE come ingresso INPUT
	pinMode(LED, OUTPUT);  // settiamo il pin LED come uscita OUTPUT

}

void loop() {
	
	durata = pulseIn(PULSANTE, HIGH);  /* assegniamo alla variabile durata, attraverso la
										funzione pulseIn() dove sono passati come parametri il pin dove è collegato il pulsante e la condizione HIGH o LOW, il tempo intercorso da quando premiamo il pulsante a quando lo rilasciamo */

	Serial.println(durata); // stampiamo il valore della variabile durata

	if(durata > 100000){   // se il valore della variabile durata è maggiore di 100000 
	statoLed = !statoLed;  // invertiamo lo stato della variabile statoLed
	}
	digitalWrite(LED, statoLed); // in funzione dello stato della variabile statoLed, il led si accende e si spegne
}

/*****************************************************************
 *                revisione sketch by Concetto G.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #20                  *  
 *                   Advanced pins, tone, pulsin, etc            * 
 *            https://www.youtube.com/watch?v=7b2X7g5qFgo        *      
 *                                                               *
 *    1.		Reference Arduino - Advanced I/O  00:06:38           *
 *		2.		tone()            								00:07:44	         *
 *		3.		noTone()					            		00:11:33	         *
 *		4.		pulseIn()						            	00:12:40	         *
 *		5.		Schema fritzing	pulsante			    00:25:10           *
 *		6.		codice	pulseIn() 					      00:28:14	         *
 *		7.		codice tone()						          00:46:25	         *
 *		8.		Schema fritzing buzzer			     	01:23:33	         *
 *		9.		codice pulseInLong()			      	01:32:03        	 *
 *                                                               *
 *****************************************************************
*/
//  -----------------> 9. pulseInLong() <-------------------

#define BUZZER 11
#define BUTTON 12

unsigned long durata;

void setup(){

	Serial.begin(9600);
	pinMode(BUTTON, INPUT);
}

void loop(){
  // assgniamo alla variabile durata attraverso la funzione pulseInLong() il tempo in millisecondi per quanto deve durare il suono
	durata = pulseInLong(BUZZER, HIGH, 0);

  // verfichiame che se la durata è maggiore di zero e il pulsante è premuto
  // stampiamo sulla seriale il valore di durata e attiviamo il buzzer
  // altrimenti teniamoil buzzer disattivato
	if(durata > 0 && digitalRead(BUTTON) == HIGH){
		Serial.println(durata);
		tone(BUZZER, durata);
	} else {
		noTone(BUZZER);
	}
}

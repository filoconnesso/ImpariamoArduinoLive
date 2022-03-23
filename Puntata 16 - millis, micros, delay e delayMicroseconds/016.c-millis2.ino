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


//  -----------------> 3. millis() doppio timer<-------------------

// due timer, non bloccanti, che lavoreranno in maniera indipendemte l'uno dall'altro, senza interferirsi

// assegnato il nome LED al pin 13
#define LED 13 
 
// definiamo una variabile di tipo Booleana chiamata status e gli assegniamo lo stato false
bool status = false;   

/* vengono definite tre variabili di nome [tempoAttuale], [tempoPrecedente] e [tempoPrecedente1] inizializzate tutte e tre con il valore di millis attuale, di tipo [unsigned long] (numero intero positivo lungo(2^32-1) poco più di 4 miliardi) */
unsigned long tempoAttuale, tempoPrecedente, tempoPrecedente1 = millis();

/* viene definita una variabile di tipo intero positivo senza segno di tipo lungo [unsigned long] chiamata timer e viene inizializzata a 1000ms (1 Ssecondo), questo è il tempo del nostro primo timer */
unsigned long timer = 1000;

/* viene definita una variabile di tipo intero positivo senza segno di tipo lungo [unsigned long] chiamata timer1 e viene inizializzata a 3000ms (3 Ssecondi), questo è il tempo del nostro secondo timer */
unsigned long timer1 = 3000;

void setup() {
	// inizializziamo la seriale
	Serial.begin(115200);
	
	// settiamo il pin LED come uscita OUTPUT
    pinMode(LED, OUTPUT);
	
	// impostiamo le variabili [tempoPrecedente] e [tempoPrecedente1] con il valore attuale del tempo millis()
	tempoPrecedente = millis();
    tempoPrecedente1 = millis();
}

void loop() {
	
	//impostiamo la variabile [tempoAttuale] con il valore attuale del tempo millis()
    tempoAttuale = millis();
	
	/* questo if è il primo timer, con cui diciamo che se la differenza del valore della variabile [tempoAttuale] meno il valore della variabile [tempoPrecedente] è maggiore o uguale al valore impostato nella variabile timer, accende o spegne il led, inoltre dato che la variabile [timer] è di tipo intero mentre le altre due [tempoAttuale] e [tempoPrecedente] sono di tipo [unsigned long] per sicurezza forziamo tutto il calcolo a [unsigned long] */
    if((unsigned long) tempoAttuale - tempoPrecedente >= timer){
		
		// viene aggiornata la variabile [tempoPrecedente] con il valore della variabile [tempoAttuale]
        tempoPrecedente = tempoAttuale;
		
		// accendiamo o spegniamo il LED in base al valore della variabile [status] che può essere [true] o [false]
        digitalWrite(LED, status);
		
		// invertiamo ilvalore della variabile [status], da true diventa false e viceversa
        status = !status;
    }
	
	/* questo if invece è il nostro secondo timer, che rispecchia le condizione del primo timer, ma con un controllo sulla variabile [timer1] */
    if((unsigned long) tempoAttuale - tempoPrecedente1 >= timer1){
		
		Serial.println("test");
    }
	
    /* Si può notare come mentre il LED si accende con una cadenza di 1s, il tempo impostato nella variabile [timer], la scritta [test] sulla seriale scorre con un tempo di 3s, come impostato nella variabile [timer1] questo dimostra come i due timer non siano di tipo bloccante e lavorino in modo indipendente */
   	
}
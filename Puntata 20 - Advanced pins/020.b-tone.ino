/*****************************************************************
 *                revisione sketch by Concetto G.                *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #20                  *  
 *                   Advanced pins, tone, pulsin, etc            * 
 *            https://www.youtube.com/watch?v=7b2X7g5qFgo        *      
 *                                                               *
 *    1.		Reference Arduino - Advanced I/O  00:06:38           *
 *		2.		tone()		            						00:07:44	         *
 *		3.		noTone()							            00:11:33	         *
 *		4.		pulseIn()							            00:12:40	         *
 *		5.		Schema fritzing	pulsante		    	00:25:10           * 
 *		6.		codice	pulseIn() 					      00:28:14	         *
 *		7.		codice tone()						          00:46:25	         *
 *		8.		Schema fritzing buzzer			    	01:23:33        	 *
 *		9.		codice pulseInLong()			      	01:32:03	         *
 *                                                               *
 *****************************************************************
*/

//  -----------------> 7. tone() <-------------------

/* *****************************************************************
 * Questo elenco  contiene tutte le definizioni delle note         *
 * a cui sono assegnate i valori delle singole frequenze in hertz  *
 ******************************************************************* */
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define BUZZER 11   // definiamo il pin 11, collegato al buzzer e lo chiamiamo BUZZER

// viene settato un array chiamato melody[] che contiene valori interi, 
// nell'esempio il nome delle frequenze delle note
// lo zero e' utilizzato come pausa, tra una nota e la successiva
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

//  array di nome noteDurations di tipo intero, che contiene la lunghezza della nota
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup(){
//  per gestire una specie di melodia  	
	tone(BUZZER, NOTE_C4); // alla variabile tone viene assegnata il pin, dove e' collegato
	                        // il buzzer e la nota da far suonare
	delay(200); // attendimo 200ms
	noTone(BUZZER); // disattiviamo il buzzer 
	tone(BUZZER, NOTE_G3); // diamo alla variabile tone un'altra nota
	delay(200);
	noTone(BUZZER);
	tone(BUZZER, NOTE_B3);
	delay(200);
	noTone(BUZZER);
	tone(BUZZER, NOTE_C4);
	delay(200);
	noTone(BUZZER);
	tone(BUZZER, 0);
	noTone(BUZZER);
/* in questo modo il codice sarà molto lungo e ripetitivo, un modo più elegnate e compatto 
 *  per eseguire la stessa melodia è usare un ciclo for e gli array sopra specificati.
    il ciclo for indica l'indice dell'array della nota e del tempo che ad ogni ciclo si vole
    far suonare*/

	for (int thisNote = 0; thisNote < 8; thisNote++) {

    // per calcolare la durata della nota, si prende un secondo (1000ms) diviso per il tipo di nota.

    // e.s. un quarto di nota  = 1000 / 4, unottavo di nota = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(BUZZER, melody[thisNote], noteDuration);

    // per distinguere le note, impostare un tempo minimo tra di loro.

    // in questo esempio utilizziasmo come pausa il tempo di durata della nota aumentato del 30% (1.30)

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // disattiviamo BUZZER

    noTone(BUZZER); 

  }
  tone(BUZZER,0); // pausa del buzzer
  noTone(BUZZER);
}

void loop(){

}

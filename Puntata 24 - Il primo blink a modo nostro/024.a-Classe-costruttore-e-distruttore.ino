/*****************************************************************
 *               revisione sketch by Concetto G.                 *
 ***************************************************************** 
 *                         Filo Connesso                         *
 *                   Impariamo Arduino Live #24                  *  
 *                     Il primo blink a modo nostro              * 
 *              https://www.youtube.com/watch?v=C9ipVaE4BMw      *        
 *                                                               *
 *             riepilogo sulle classi             00:06:40       *
 *                                                               *
 *****************************************************************
*/

class classePrincipale { // definita una classe chiamata classePrincipale
	int intero; // inizializzare la variabile 
	public :
	classePrincipale(){ // costruttore della classe
		 
	}
	~classePrincipale(){ // distruttore della classe
		
	}
	void setIntero(int nuovointero){ // metodo della classe  con cui settiamo il valore della variabile intero
		intero = nuovointero;
	}
	int getIntero() {
		return intero;
	}
}; // chiusura della classe

classePrincipale miaparola;    // creiamo l'oggetto della classe
void setup(){
	Serial.begin(9600);
	while(!Serial);
	/* utilizziamo quattro oggetti (mia parola) e li settiamo con il metodo della classe
	   (setIntero) con valori diversi e ne stampiamo il valore, una sola funzione viene
	   utilizzata (n)volte */
	miaparola.setIntero(20); 
	Serial.println(miaparola.getIntero());
	miaparola.setIntero(30); 
	Serial.println(miaparola.getIntero());
	miaparola.setIntero(50); 
	Serial.println(miaparola.getIntero());
	miaparola.setIntero(10); 
	Serial.println(miaparola.getIntero());
	
}

void loop(){
	
	
}

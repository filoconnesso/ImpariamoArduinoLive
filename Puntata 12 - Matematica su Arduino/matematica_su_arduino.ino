/*
  Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
  Puntata 12 di Impariamo Arduino Live : https://www.youtube.com/watch?v=2SrmZFKeFvg
  Esempi sulle funzioni matematiche di Arduino
  Creato da : Mirko Pacioni
  Licenza : GPL v3
*/


void setup() {
   //Avvio la seriale
   Serial.begin(9600);
   //Aspetto che venga aperto il Monitor Seriale
   while(!Serial);
   //Stampo il valore assoluto della variabile
   Serial.println(abs(30));
   //Stampo il valore assoluto della variabile
   Serial.println(abs(-30));
   //Per come è concepita la funzione abs per non avere comportamenti indesiderati evitare di usare funzioni all'interno di esso
   //es. evitare abs(x++);
   //Constrain costringe un valore a restare in un range di valori ben definiti
   Serial.println(constrain(120, 30, 110));
   //map permette di rimappare un valore di un range di valori in un nuovo range di valori
   Serial.println(map(100,0,200,0,1000));  
   //max calcola il massimo tra due valori 
   Serial.println(max(3,5)); //5
   //min calcola il minimo tra due valori
   Serial.println(min(3,5)); //3
   //pow calcola applica l'esponente a per la potenza ad un numero, restituisce un valore in double. In arduino non esiste l'operatore "^"
   Serial.println(pow(2,4));
   //sq calcola il quadrato di un numero, restituisce un valore in double
   Serial.println(sq(4));
   //sqrp calcola la radice quadrata di un numero
   Serial.println(sqrt(2));
   //cos restituisce il coseno di un angolo in radianti con un un valore da -1 a 1
   Serial.println(cos(45));
   //sin restituisce il seno di una angolo in radianti con un valore da -1 a 1
   Serial.println(sin(180));
   //tan restituisce la tangente di un angolo in radianti con un valore da -infinito a infinito
   Serial.println(tan(360));
   
}

void loop() {

  static int x1 = 0;
  static int x2 = 0;
  static int y1 = 200;
  static int y2 = 200;
   /*
  //l'operatore composto ++ incrementa di 1 la variabile dopo averla utilizzata
  //l'operazione corrisponde a una somma del tipo : x = x+1 o x += 1;
  Serial.print(x1++);
  Serial.print(" ");
  //se si usa l'operatore ++ prima della variabile, quest'ultima viene incrementata prima di essere utilizzata
  Serial.print(++x2);
  Serial.println();
*/
/*
  //l'operatore composto -- decrementa di 1 la variabile dopo averla utilizzata
  //l'operazione corrisponde a una differenza del tipo : y = y-1 o y -= 1
  Serial.print(y1--);
  Serial.print(" ");
  //se si usa l'operatore -- prima della variabile, quest'ultima viene decrementata prima di essere utilizzata
  Serial.print(--y2);
  Serial.println();
*/
  int risultato = 2*2;
  float risultato1 = 4/(float)3;
  float risultato2 = 4%3;

  Serial.println(risultato);
  Serial.println(risultato1);
  Serial.println(risultato2);

  delay(2000);

}

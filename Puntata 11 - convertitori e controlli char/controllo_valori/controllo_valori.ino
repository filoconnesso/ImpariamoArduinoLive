/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 11 di Impariamo Arduino Live : https://www.youtube.com/watch?v=JXEx49cuLww
* Controllo valori char
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

char char1 = 'f'; //a-z A-Z
char char2 = '9'; //a-z A-Z 0-9
char char3 = 65; //numerico ascii di A
char char4 = 13; //valore di controllo tasto INVIO
char char5 = '4'; //cifra 4
char char6 = ' '; //spazio
char char7 = 0x31; //cifra 1
char char8 = 'A'; //lettera A maiuscola
char char9 = 13; //char tasto INVIO
char char10 = '&'; //carattere speciale "e commerciale"
char char11 = ' '; //spazio
char char12 = 'A'; //lettera A maiuscola
char char13 = '\t'; //whitespace (TABULAZIONE)


void setup() {
  //Avvio la seriale
  Serial.begin(9600);
  //Attendo che venga aperto il Monitor Seriale
  while(!Serial);

  //isAlpha controlla se il char è di tipo alfabetico a-z o A-Z
  if(isAlpha(char1)) {
    Serial.println("è un alfabetico");
  }

  //isAlphaNumeric controlla se il char è di tipo alfanumerico a-z o A-Z o 0-9
  if(isAlphaNumeric(char2)) {
    Serial.println("è un alfanumerico");
  }

  //isAscii controlla se un char è un valore ascii valido 65 = 'A' è un valore ascii valido
  if(isAscii(char3)) {
    Serial.println("è un ascii");
  }

  //isControl permette di controllare se un ascii corrisponde a un tasto di controllo 13 = INVIO
  if(isControl(char4)) {
    Serial.println("è un char di controllo");
  }

  //isDigit controlla se il char è un valore numerico es. 4
  if(isDigit(char5)) {
    Serial.println("è un char numerico");
  }

  char frase[] = "la temperatura è di 30 gradi";

  for(int i = 0; i <= sizeof(frase) - 1; i++) {
    if(isDigit(frase[i])) {
      Serial.println("c'è un numero");
      break;
    }
  }

  //isGraph controlla se il valore del char stampa un contenuto realmente visibile, lo spazio non è tra questi
  if(isGraph(char6)) {
    Serial.println("il char stampa un valore");
  } else {
    Serial.println("il char non stampa un valore");
  }

  //isHexadecimalDigit controlla se il carattere corrisponde al valore esadecimale di una cifra
  if(isHexadecimalDigit(char7)) {
    Serial.println("il carattere è un numero in esadecimale");
  }

  //isLowerCase controlla se il carattere è in minuscolo
  if(isLowerCase(char8)) {
    Serial.println("il carattere è minuscolo");
  } else {
    Serial.println("il carattere non è minuscolo");
  }

  //isPrintable controlla se stampa un contenuto, anche lo spazio viene considerato
  if(isPrintable(char9)) {
    Serial.println("il char ha un contenuto stampabile");
  } else {
    Serial.println("il char non ha un contenuto stampabile");
  }

  //isPuntct controlla se un carattere è tra i caratteri speciali
  if(isPunct(char10)) {
    Serial.println("il char è un carattere speciale");
  }

  //isSpace controlla se un carattere è uno spazio
  if(isSpace(char11)) {
    Serial.println("il char è uno spazio");
  }

  //isUpperCase controlla che un char è in maiuscolo
  if(isUpperCase(char12)) {
    Serial.println("il char è in maiuscolo");
  } else {
    Serial.println("il char non è in maiuscolo");
  }

  //isWhitespace controlla se il char è una tabulazione "\t"
  if(isWhitespace(char13)) {
    Serial.println("il char è un whitespace");
  }
  
 
}

void loop() {
 
  

}

/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 9 di Impariamo Arduino Live : https://www.youtube.com/watch?v=aUWFLuYPivI
* Esempi pratici sugli array di char
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

char lettera = 'A'; //char semplice 'A' = 65

char stringa[] = "test"; //array di char, è come se il nostro array fosse {'t','e','s','t','\0'}

char stringa1[] = {'t','e','s','t', '\0'}; //array di char, il "\0" è il fine array (0 o NULL)
char stringa2[] = {116, 101, 115, 116, 0}; //array di char, è come sopra ma con i valori numerici ASCII

//quando un testo in un array char è troppo lungo è possibile dividerlo in questo modo :
char stringa_composta[] = "questa è una parte di frase,"
                          " questa è un'altra parte di frase,"
                          " questa è l'ultima parte di frase";

//Questo qui sotto è un array di array char, il * è un puntatore che ci permette di creare questa tipologia di array
char *stringhe[] = {"stringa1", "stringa2", "stringa3", "stringa4"};

//per capire meglio gli array di array char, questo che trovi qui sotto è la stessa cosa scritta sopra :

char arr_stringa_1[] = "arr_stringa_1";
char arr_stringa_2[] = "arr_stringa_2";
char arr_stringa_3[] = "arr_stringa_3";
char arr_stringa_4[] = "arr_stringa_4";

//gli array di char scritti qui sopra vengono inseriti all'interno dell'array di array char qui sotto :
char *stringhe1[] = {arr_stringa_1, arr_stringa_2, arr_stringa_3, arr_stringa_4};


void setup() {
  Serial.begin(9600);
  while(!Serial);
  //Vari print dei char inizializzati a inizio codice
  Serial.println(stringa);
  Serial.println(stringa1);
  Serial.println(stringa2);
  Serial.println(sizeof(stringa));
  Serial.println(sizeof(stringa1));
  Serial.println(sizeof(stringa2));
  Serial.println(stringa_composta);
  
  //per elencare un array di array char è possibile usare un ciclo for come questo :
  for(int i = 0; i < 4; i++) {
    Serial.println(stringhe[i]);
  }
  for(int i = 0; i < 4; i++) {
    Serial.println(stringhe1[i]);
  }

}

void loop() {
  
}

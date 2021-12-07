/*
  Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
  Puntata 10 di Impariamo Arduino Live : https://www.youtube.com/watch?v=wyS_4ogwdwE
  Esempi per utilizzare i metodi della classe String
  Creato da : Mirko Pacioni
  Licenza : GPL v3
*/

//Creo una variabile String "parola" con il valore "valerio"
String parola = "valerio";
//Creo una variabile String "parola1" con il valore "valerioderampellis"
String parola1 = "valerioderampellis";
//Creo una variabile intera "numero1" con il valore 13
int numero1 = 13;
//Creo una variabile String con una frase che contiene il costruttore String con il valore della variabile intera "numero1"
//In questo caso possiamo concatenare le varie parti della stringa con l'operatore "+"
//Se non utilizzassimo String(numero1) nel concatenamento della stringa il compilatore vedrà tutto come una somma matematica, restituendo un errore
//String(valore) permette di convertire int, float, double, long e char in String
String numero = "la temperatura è di " + String(numero1) + " gradi";

void setup() {
  //Avviamo la seriale a 9600
  Serial.begin(9600);
  //Aspettiamo che il Monitor Seriale venga aperto
  while (!Serial);
  //Seleziona il char della posizione 3 della variabile String "parola", contenente il valore "valerio"
  Serial.println(parola.charAt(3)); //stamperà sul monitor seriale "e"
  //compareTo permette di controllare se una stringa è contenuta in una seconda stringa
  //in base alla posizione della prima stringa rispetto al seconda stringa si avranno 3 valori
  //0 : le stringhe sono uguali
  //< 0 (valore negativo) : la stringa 1 compare a inizio stringa 2
  //> 0 (valore positivo) : la stringa 1 compare alla fine della stringa 2
  //primastringa.compareTo(secondastringa), nel nostro caso confronterà "valerio" con "valerioderampellis"
  //Qui sotto la dimostrazione :
  if (parola.compareTo(parola1) == 0) {
    Serial.println("le stringhe sono uguali");
  }
  if (parola.compareTo(parola1) < 0) {
    Serial.println("stringa è all'inizio di stringa1");
  }
  if (parola.compareTo(parola1) > 0) {
    Serial.println("stringa è alla fine di stringa1");
  }

  //Il metodo concat di String è un metodo più elegante di utilizzare l'operatore "+" per concatenare vari valori insieme per poi inserirli in uno String
  //la soluzione classica per eseguire il concatenamento mostrato qui sotto può essere questo :
  //String("la temperatura è di " + String(gradi) + " gradi);
  //concat provvede a convertire in modo automatico i valori di riferimento che gli diamo, ragione per la quale è possibile concatenare qualsisi valore
  //Creo un array di char "frase[]" che contiene la stringa "la temperatura è di"
  char frase[] = "la temperatura  è di ";
  //creo una variabile float "temperatura_sensore" con il valore 30
  float temperatura_sensore = 30;
  //creo una variabile String "gradi" con il valore "gradi"
  String gradi = " gradi";
  //Creo una nuova variabile String "frase_temperatura" che conterrà la futura frase concatenata
  String frase_temperatura;
  //Concateno l'array di char "frase[]" al valore attuale della String "frase_temperatura"
  frase_temperatura.concat(frase);
  //Concateno la variabile float "temperatura_sensore" al valore attuale della String "frase_temperatura"
  frase_temperatura.concat(temperatura_sensore);
  //Concateno la variabile String "gradi" al valore attuale della String "frase_temperatura"
  frase_temperatura.concat(gradi);
  Serial.println(frase_temperatura); //verrà stampata la frase "la temperatura è di 30 gradi"

  //Il metodo endsWith permette di controllare se il valore della prima String finisce con il valore della seconda String
  //questo metodo restituisce true se la prima parola finisce con la seconda parola
  //restituisce false  se la prima parola non finisce con la seconda parola
  //Nel caso mostrato qui sotto il risultato sarà false e quindi non verrà stampato nulla sulla seriale relativo a questo controllo
  //Creo una nuova String "primaparola" con valore "amica"
  String primaparola = "amica";
  //Creo una nuova String "secondaparola con valore "gatto"
  String secondaparola = "gatto";
  if (primaparola.endsWith(secondaparola)) {
    Serial.println("la prima parola finisce con la seconda parola");
  }

  //I metodi equals ed equalsIgnoreCase sono due metodi che permettono di controllare se due String sono identiche
  //equals da priorità alla presenza di lettere maiuscole e minuscole, nell'esempio qui sotto darà quindi false
  //equalsIngoreCase non considera le maiuscole e minuscole, di conseguenza nel nostro caso darà true
  //Creo una String "hello1" con valore "hello"
  String hello1 = "hello";
  //Creo un String "hello2" con valore "HELLO"
  String hello2 = "HELLO";
  //controllo con equals se la String "hello1" è identica a "hello2", non lo sarà
  if (hello1.equals(hello2)) {
    Serial.println("le due stringhe sono uguali");
  } else {
    Serial.println("le due stringhe sono diverse");
  }
  //controllo con equalsIngoreCase se la String "hello1" è identica a "hello2", in questo caso lo sarà
  if (hello1.equalsIgnoreCase(hello2)) {
    Serial.println("le due stringhe sono uguali");
  } else {
    Serial.println("le due stringhe sono diverse");
  }

  //I metodi indexOf e lastIndexOf restituiscono la posizione dell'inizio della stringa indicata
  //il suo utilizzo è stringa.indexOf(carattere o parola) o stringa.lastIndexOf(carattere o parola)
  //Creo una String "frase2" con valore "ubi fa i biscotti"
  //la String "frase2" verrà usata nei prossimi esempi
  String frase2 = "ubi fa i biscotti";
  //Controllo la posizione della parola "biscotti" partendo dall'inizio
  Serial.println(frase2.indexOf("biscotti")); //stamperà 9 
  //Controllo la posizione della parola "biscotti" partendo dala fine
  Serial.println(frase2.lastIndexOf("biscotti")); //stamperò 9
  
  //Il metodo length permette di sapere il numero di caratteri inclusi in una stringa, compresi gli spazi
  Serial.println("la frase ha " + String(frase2.length()) + " caratteri");

  //Il metodo remove permette di eliminare una porzione specifica di una stringa
  //In questo caso verranno eliminati tutti i caratteri della String "frase2" dalla posizione 4 e i successivi 5 caratteri 
  frase2.remove(4, 5);
  Serial.println(frase2); //stamperò "ubi biscotti"
  
  //Il metodo replace permette di sostituire parte di una stringa con un nuovo valore
  //Nel caso seguente la parola "biscotti" verrà sostituita da "torte"
  frase2.replace("biscotti", "torte");
  Serial.println(frase2); //stamperò "ubi torte"

  //Il metodo c_str() permette di restituire il valore in C-string della String corrente
  //Creo una nuova String "name" e assegno a quest'ultima il valore "Ubi De Feo"
  String name = "Ubi De Feo";
  //Stampo la stringa in C-string
  Serial.println(name.c_str());

  //getBytes permette di prelevare il valore in byte di una String
  //Creo un array di byte chiamato "parziale" con un valore massimo di elementi di 5
  byte parziale[5];
  //Inserisco con getBytes i byte della String "name" nell'array byte "parziale", partendo dalla posizione 0 fino alla posizione 5
  //l'array parziale assumerà questi valori : {85,98,105,32,68}
  name.getBytes(parziale, 5);
  //Stampo il valore della posizione 0 dell'array "parziale"
  //la posizione 0 della String continene "U", di conseguenza il suo valore in byte è 85
  Serial.println(parziale[0]); //stamperò 85

  //setCharAt permette di sostituire un carattere di una variabile String
  //creo una variabile String "parola10" con il valore "amica"
  String parola10 = "amica";
  //uso setCharAt per sostituire il carattere della posizione 4 di String "parola10" con il valore "o"
  //setCharAt prevede la lettura della variabile String dalla posizione 0
  //0 = a, 1 = m, 2 = i, 3 = c, 4 = a
  parola10.setCharAt(4, 'o');
  //diventerà quindi : 
  //0 = a, 1 = m, 2 = i, 3 = c, 4 = o
  Serial.println(parola10); //stamperò quindi "amico"

  //startsWith è l'antagonista del metodo endsWith e permette di controllare se una stringa inizia con una serie di caratteri indicati
  //Creo una variabile String "parola11" con il valore "amico"
  String parola11 = "amico";
  //Creo una variabile String "parola12" con il valore "am"
  String parola12 = "am";
  //In questo caso controllando le due String create pocanzi si la risposta del metodo sarà true, quindi stamperà il messaggio in seriale
  //true : la prima stringa inizia con il valore della seconda stringa
  //false : la prima stringa non inizia con il valore della seconda stringa
  if (parola11.startsWith(parola12)) {
    Serial.println("parola 1 inizia con parola 2"); //stamperà "parola 1 inizia con parola 2"
  }

  //substring permette di tagliare la stringa attuale e stampare tutti i valori dall'indice indicato
  //per quanto riguarda il valore di "parola11" e cioè "amico", il risultato dell'operazione indicato qui sotto sarà "mico"
  Serial.println(parola11.substring(1));

  //toCharArray permette di strasformare Strin in un array di char
  //Creo una nuova variabile String "valore" con il valore "valerio"
  String valore = "valerio";
  //Creo un array di char "arraychar[20]" che sarà il nostro futuro array di char dopo la conversione
  char arraychar[20];
  //creo una variabile int "lunghezza" che conterrà la lunghezza della String attuale
  //usiamo "+1" poichè toCharArray non tiene conto del fine array "\0" e quindi se lo evitassimo
  //il nostro array di char non conterrà il suo ultimo carattere
  int lunghezza = valore.length() + 1;
  //Riempio l'array di char con la String "valore"
  valore.toCharArray(arraychar, lunghezza);
  Serial.println(arraychar); //stamperò l'array di char appena creato sulla seriale, quindi "valerio"

  //Il metodo trim permette di eliminare tutti gli spazi superflui
  //Il metodo toInt permette di convertire il valore di una String in un valore numerico intero (int)
  //Il metodo toFloat permette di convertire il valroe di una String in un valore numerico decimale (float)
  //Il metodo toDouble permette di convertire il valore di una String in un valore numerico decimale (double)
  //Creo una nuova String "numero10" con valore 20
  String numero10 = " 20 ";
  //Stampo in seriale il valore di "numero10" senza modifiche " 20 "
  Serial.println(numero10);
  //elimino gli spazi superflui
  numero10.trim();
  //Stampo in seriale il valore di "numero10" senza spazi "20", è ancora una stringa
  Serial.println(numero10);
  //Converto la String "numero10" in intero (int) e inserisco il suo valore in una variabile "numero11"
  int numero11 = numero10.toInt();
  //Stampo in seriale il valore di numero11
  Serial.println(numero11);
  //Converto la String "numero10" in decimale (float) e inserisco il suo valore in una variabile "numero12"
  float numero12 = numero10.toFloat();
  //Stampo in seriale il valore di numero11
  Serial.println(numero12);
  //Converto la String "numero10" in decimale (double) e inserisco il suo valore in una variabile "numero13"
  double numero13 = numero10.toDouble();
  //Stampo in seriale il valore di numero13
  Serial.println(numero13);

}

void loop() {


}

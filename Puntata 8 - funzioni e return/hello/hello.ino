/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 8 di Impariamo Arduino Live : https://youtu.be/nKjv-KkZZig
* In questo esempio creiamo una funzione che sfrutta il return per salutare l'utente una volta settato il nome desiderato
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//creo una funzione "hello" di tipo String con un argomento anch'esso String, questa funzione conterrà un return (ritorno) con una stringa preformattata e aggiornata in base al nome indicato dall'utente
//String yourName è l'argomento che conterrà il nome desiderato
String hello(String yourName) {
  //return permette di ritornare la frase "Ciao, nome", trasformando la funzione "hello" in una sorta di variabile stringa preformattata
  //il valore yourName possiamo settarlo durante l'esecuzione del programma
  return "Ciao, " + yourName;
}

void setup() {
  //apro la seriale con baudrate 9600, ricorda di settare lo stesso baudrate anche nel Monitor Seriale
  Serial.begin(9600);
  //attendo affinchè il Monitor Seriale non venga aperto
  while(!Serial);
  //stampo una riga utilizzando come stringa di riferimento la funzione "hello" creata precedentemente
  //nelle parentesi indichiamo il nome "pippo" e quindi la nostra funzione "hello" ritornerà come valore "Ciao, pippo"
  //la frase "Ciao, pippo" verrà stampata sulla seriale
  Serial.println(hello("pippo"));

  //il codice si conclude qui entrando nel loop
  //per eseguire il codice dovrai chiudere il Monitor Seriale, riavviare la board e riaprire il Monitor Seriale
}

void loop() {
  
}

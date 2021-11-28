/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 7 di Impariamo Arduino Live : https://youtu.be/GGcnIBsYJ5k
* Il codice permette di capire il funzionamento del continue, in sostanza il ciclo for verrà bloccato e ricomincerà da capo quando il valore di x varrà 5
* in questo caso specifico il programma scriverà in seriale tutti i valori tranne 5
* questa operazione verrà eseguita una sola volta all'avvio della scheda e soltando aprendo il Monitor Seriale
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

void setup() {

  //avvio la seriale con baudrate 115200, ricorda di settare lo stesso baudrate nel Monitor Seriale
  Serial.begin(115200);
  //il ciclo while blocca l'esecuzione del resto del codice affinchè Serial non ritorna un valore true
  //per far in modo che Serial ritorni true bisogna aprire il Monitor Seriale
  //affinchè non si apre il Monitor Seriale il nostro codice resterà bloccato in questo punto e la tua board non eseguirà il resto del programma
  while(!Serial);

  //creiamo una variabile x e impostiamo il suo valore iniziale a 0
  int x = 0;
  //entriamo in un ciclo while che continuerà affinchè il valore di x non supererà 9
  //affinchè x è minore di 9 il ciclo while continuerà a eseguire le operazioni al suo interno
  //quando x assumerà un valore maggiore di 9 il ciclo verrà interrotto e il programma continuerà con il resto del codice
  while(x < 9) {
    //con x++ aumento di 1 il valore di x, in altre parole è come se facessimo x = x + 1
    x++;
    //l'if controlla che il valore di x sia uguale a 5, l'operatore == è un'eguaglianza
    if(x == 5) {
      //se x assume il valore 5 il codice esegue continue
      //continue blocca il ciclo while e lo fa ripartire da capo, quindi Serial.println(x) non verrà richiamato
      continue;   
    }  
    //Serial.println(x) scrive ad ogni step di ciclo una riga sulla seriale
    //in questo caso specifico viene scritto il valore di x
    //Serial.println(x) non verrà eseguito solo nel caso in cui x assume valore 5
    //sulla seriale verranno scritte le cifre da 1 a 9 escludendo il 5
    Serial.println(x);
  }

  //quando il programma esce dal while entra nel loop, in questo caso non accadrà più nulla

}

void loop() {
  

}

/*
* Esempio per Arduino e altre board (Board usata nel corso Arduino Nano RP2040 Connect)
* Puntata 8 di Impariamo Arduino Live : https://youtu.be/nKjv-KkZZig
* Esempio su come creare una funzione che estrae tutti gli elementi di un'array
* Nel codice creiamo una funzione con due argomenti, entrambi gli argomenti della funzione sono di tipo int, il primo accoglierà un array di int
* il secondo il numero di elementi presenti dell'array che inseriremo manualmente
* Creato da : Mirko Pacioni
* Licenza : GPL v3
*/

//creo un array di int con valori a caso
int arr[] = {2,4,6,20,43};

//creo un void che chiamo arrayExploder che rappresenterà la nostra funzione la quale conterrà le istruzioni per stampare tutti i valori dell'array scelto
//la funzione ha due argomenti, il primo ci permette di indicare l'array da "esplodere" e il secondo argomento permette di indicare il numero di elementi nell'array, in questo caso 5
//non usiamo la funzione sizeof, vista nella puntata precedente sui cicli, perchè per usarla in questo caso dovremmo sfruttare i puntatori che non abbiamo ancora trattato 
void arrayExploder(int myArr[], int numElements) {
  //il for qui sotto permette di stampare tutti i valori dell'array sulla seriale
  //nel caso specifico "i" assumerà un  valore da 0 a 4 e il ciclo continuerà affinchè "i" è minore di 5
  for(int i = 0; i < numElements; i++)  {
    //Stampo il valore attuale preso dall'array
    Serial.println(myArr[i]);
  }
}

void setup() {
  //avvio la seriale con baudrate a impostato a 9600 baud
  Serial.begin(9600);
  //il while blocca il codice affinchè non viene aperto il Monitor Seriale
  while(!Serial);
  //richiamo la funzione arrayExploder creata precedentemente che stampa tutti i valori dell'array selezionato
  //come specificato precedetemente negli argomenti indichiamo l'array "arr" inizializzato a inizio codice e indichiamo il numero degli elementi dell'array, cioè 5
  arrayExploder(arr, 5);

  //da questo momento in poi il programma non eseguirà più nulla ed entrerà nel loop
  //per rieseguire le operazioni descritte precedentemente si dovrà chiudere il Monitor Seriale, riavviare la board e riaprire il Monitor Seriale
}

void loop() {
  

}
